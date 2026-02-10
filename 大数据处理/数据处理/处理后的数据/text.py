#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
merge_samples.py

流程：
  1. 读 processed_extracted_1to{r}.csv，取出正样本 P 条；
  2. 读别人文件 1-{r or mapped}_processed_file.csv，取出全部负样本，随机抽 P*r 条；
  3. 正负各自再取一半：P/2, Pr/2；
  4. 合并后从中再抽 P 条，保证最后条数 = P；
  5. 按 fault 排序（0 在前）并输出 merged 文件。

用法：
    python merge_samples.py
"""
import pandas as pd

def merge_and_reduce(r, orig_prefix, other_map, output_prefix):
    # 1. 读取自己的正样本 P
    orig_file = f"{orig_prefix}_1to{r}.csv"
    df_orig = pd.read_csv(orig_file)
    df_pos = df_orig[df_orig['fault'] == 1]
    P = len(df_pos)

    # 2. 从别人文件抽 P*r 条负样本
    other_file = f"{other_map[r]}.csv"
    df_other = pd.read_csv(other_file)
    df_neg_pool = df_other[df_other['fault'] == 0]
    neg_needed = P * r
    df_neg = df_neg_pool.sample(n=neg_needed, random_state=42,
                                replace=len(df_neg_pool) < neg_needed)

    # 3. 各自再取一半
    df_pos_half = df_pos.sample(frac=0.5, random_state=42)
    df_neg_half = df_neg.sample(frac=0.5, random_state=42)

    # 中间集合并
    df_mid = pd.concat([df_pos_half, df_neg_half], axis=0)

    # 4. 从中再抽 P 条
    df_final = df_mid.sample(n=P, random_state=42)

    # 5. 按 fault 排序（0 在前）
    df_final = df_final.sort_values('fault').reset_index(drop=True)

    out_file = f"{output_prefix}_merged_1to{r}.csv"
    df_final.to_csv(out_file, index=False)
    print(f"Saved {out_file}  (总={len(df_final)}, 0={len(df_final[df_final['fault']==0])}, 1={len(df_final[df_final['fault']==1])})")

if __name__ == '__main__':
    # 你的文件前缀
    orig_prefix = 'processed_extracted'
    # 别人文件前缀映射
    other_map = {
        1: '1-1_processed_file',
        10: '1-10_processed_file',
        20: '1-30_processed_file',  # 用 1-30 文件来抽 1:20 的负样本
    }
    # 输出前缀
    output_prefix = 'processed_extracted'

    for ratio in (1, 10, 20):
        merge_and_reduce(ratio, orig_prefix, other_map, output_prefix)
