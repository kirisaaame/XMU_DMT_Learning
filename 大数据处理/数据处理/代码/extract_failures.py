#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
extract_failures.py

根据 ssd_failure_label.csv 中的 (model, failure_time, disk_id)，
到对应的按天存储的日志文件中提取出发生故障当天的全部 SMART 指标行。

用法：
    python extract_failures.py --label_csv ./data/ssd_failure_label.csv  --data_dir ./data  --output_csv failures_extracted.csv

输出文件 failures_extracted.csv 包含：
disk_id, ds, model, n_1, r_1, ..., n_245, r_245, failure_time
"""

import os
import argparse
import pandas as pd
from tqdm import tqdm

def extract_failures(label_csv: str, data_dir: str, output_csv: str):
    # 1. 读取故障标签
    labels = pd.read_csv(label_csv, parse_dates=['failure_time'])
    # 增加一个日期字段以匹配日志文件名
    labels['date_str'] = labels['failure_time'].dt.strftime('%Y%m%d')

    # 准备结果列表
    extracted = []

    # 分组按日期一次读文件
    for date_str, grp in tqdm(labels.groupby('date_str'), desc='日期'):
        # 决定文件夹：根据年份
        year = int(date_str[:4])
        if year == 2018:
            folder = 'smartlog2018ssd'
        elif year == 2019:
            folder = 'smartlog2019ssd'
        else:
            raise ValueError(f"无法处理年份 {year}")

        csv_path = os.path.join(data_dir, folder, f"{date_str}.csv")
        if not os.path.exists(csv_path):
            print(f"警告: 未找到日志文件 {csv_path}，跳过")
            continue

        # 2. 读取当天日志，只取 disk_id、ds、model 和所有 n_*,r_* 列
        sample = pd.read_csv(csv_path, nrows=0)
        usecols = [c for c in sample.columns
                   if c in ('disk_id','ds','model') or c.startswith('n_') or c.startswith('r_')]
        df_day = pd.read_csv(csv_path, usecols=usecols, na_values=['\\N'])

        # 3. 对每条故障记录，按 disk_id and model 匹配日志行
        for _, row in grp.iterrows():
            did = row['disk_id']
            mdl = row['model']
            ftime = row['failure_time']
            # 筛选
            match = df_day[
                (df_day['disk_id'] == did) &
                (df_day['model'] == mdl)
            ]
            if match.empty:
                print(f"未在 {date_str}.csv 中找到 disk_id={did}, model={mdl}")
                continue
            # 如有多条，则全部取出
            for _, mrow in match.iterrows():
                out = mrow.to_dict()
                out['failure_time'] = ftime
                extracted.append(out)

    # 4. 合并结果并保存
    if extracted:
        df_out = pd.DataFrame(extracted)
        # 将 ds 保持为 YYYYMMDD 格式字符串
        df_out['ds'] = df_out['ds'].astype(str)
        df_out.to_csv(output_csv, index=False)
        print(f"成功提取 {len(df_out)} 条故障日志，已保存到 {output_csv}")
    else:
        print("未提取到任何记录。")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="按故障标签提取日志行")
    parser.add_argument('--label_csv', required=True,
                        help='ssd_failure_label.csv 路径')
    parser.add_argument('--data_dir', required=True,
                        help='包含 smartlog2018ssd/ 和 smartlog2019ssd/ 根目录')
    parser.add_argument('--output_csv', default='failures_extracted.csv',
                        help='输出提取结果 CSV 路径')
    args = parser.parse_args()
    extract_failures(args.label_csv, args.data_dir, args.output_csv)
