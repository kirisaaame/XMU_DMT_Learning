#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
process_extracted_only.py

只对 failures_extracted.csv （提取出的故障记录）做清洗、归一化和可视化，
并在结果上按 1:1、1:10、1:20 下采样输出训练集。

用法：
    python process_extracted_only.py --input_csv failures_extracted.csv --output_prefix processed_extracted
"""

import argparse
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import MinMaxScaler

# 设置中文字体和负号显示
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定黑体
plt.rcParams['axes.unicode_minus'] = False    # 解决负号 '-' 显示为方块的问题


def main(input_csv, output_prefix):
    # 1. 读取并删除 failure_time
    df = pd.read_csv(input_csv, na_values=['\\N'])
    if 'failure_time' in df.columns:
        df = df.drop(columns=['failure_time'])

    # 2. 保留前三列
    df_base = df[['disk_id','ds','model']].copy()

    # 3. 筛选 r_* 列：空值率 <50%，fillna(0) 并重命名为 S*
    r_cols = [c for c in df.columns if c.startswith('r_')]
    keep_r = [c for c in r_cols if df[c].isna().mean() < 0.5]
    df_r = df[keep_r].fillna(0)
    df_r.columns = [c.replace('r_','S') for c in keep_r]

    # 4. Min–Max 归一化
    scaler = MinMaxScaler()
    S_cols = df_r.columns.tolist()
    df_r[S_cols] = scaler.fit_transform(df_r[S_cols])

    # 5. 合并回去，补上 fault 列（这里所有都是故障样本）
    df_processed = pd.concat([df_base, df_r], axis=1)
    df_processed['fault'] = 1

    # 6. 保存整体处理结果
    out_all = f"{output_prefix}.csv"
    df_processed.to_csv(out_all, index=False)
    print(f"已保存清洗归一化数据到 {out_all}")

    # 7. 绘图：帮助特征处理同学
    # 7.1 缺失率（原始 r_* 计算）
    miss_rate = df[r_cols].isna().mean() * 100
    plt.figure(figsize=(6,8))
    miss_rate[keep_r].sort_values().plot.barh()
    plt.xlabel('缺失率 (%)')
    plt.title('原始 r_* 列缺失率')
    plt.tight_layout()
    plt.show()

    # 7.2 相关性热图
    corr = df_processed[S_cols].corr()
    plt.figure(figsize=(10,8))
    im = plt.imshow(corr, vmin=-1, vmax=1, aspect='auto')
    plt.colorbar(im, shrink=0.8)
    plt.xticks(range(len(S_cols)), S_cols, rotation=90)
    plt.yticks(range(len(S_cols)), S_cols)
    plt.title('S* 特征相关性热图')
    plt.tight_layout()
    plt.show()

    # 7.3 前 3 个特征箱线图
    for feat in S_cols[:3]:
        plt.figure(figsize=(6,4))
        plt.boxplot([df_processed[feat]], labels=['故障'])
        plt.title(f'{feat} 在故障样本上的分布')
        plt.tight_layout()
        plt.show()

    # 8. 按 1:1、1:10、1:20 下采样负样本（在这里我们用“复制正样本”做示例，
    #    因为没有真实负样本），用于构造平衡集。
    pos = df_processed[df_processed['fault']==1]
    for r in (1,10,20):
        n_pos = len(pos)
        neg_s = pos.sample(n=n_pos*r, replace=True, random_state=42)
        out = pd.concat([pos, neg_s]).sample(frac=1, random_state=42).reset_index(drop=True)
        fn = f"{output_prefix}_1to{r}.csv"
        out.to_csv(fn, index=False)
        print(f"已保存 {fn}  (正样本={n_pos}, 负样本={len(neg_s)})")

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="只处理提取记录，支持中文绘图")
    parser.add_argument('--input_csv', required=True, help='failures_extracted.csv 路径')
    parser.add_argument('--output_prefix', default='processed_extracted', help='输出前缀')
    args = parser.parse_args()
    main(args.input_csv, args.output_prefix)
