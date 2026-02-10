#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import editdistance
import numpy as np
import pandas as pd
import requests
from tqdm import tqdm
from transformers import pipeline

# ========= 配置区域 =========
DATA_PATH     = "C:/Users/admin/Desktop/作业/社交网络/作业2/QuestionAnswerKB-2025-03-28.xlsx"
BASELINE_URL  = "http://127.0.0.1:8000/searchanswer/"
DEEPSEEK_URL  = "http://127.0.0.1:8000/deepseekanswer/"
HF_MODEL_NAME = "bert-large-uncased-whole-word-masking-finetuned-squad"

# 最多只测试 N 条样本
MAX_SAMPLES   = 100

# ========= 读取测试数据 =========
def load_data(path):
    df = pd.read_excel(path, engine="openpyxl")
    df = df.rename(columns={"question":"question","answer":"answer"})
    df["context"] = df["question"]
    df = df.dropna(subset=["question","answer"])
    return df[["question","context","answer"]].to_dict(orient="records")

# ========= 调用 Baseline 接口 =========
def call_baseline(q):
    try:
        r = requests.get(
            BASELINE_URL,
            params={"id":"chatbotsendbtn","text":q},
            timeout=30
        )
        r.raise_for_status()
        js = r.json()
        return js.get("answer_exact",""), js.get("answer_app","")
    except Exception as e:
        print(f"[警告] Baseline 调用失败：{e}")
        return "", ""

# ========= 调用 DeepSeek 接口 =========
def call_deepseek(q):
    try:
        r = requests.get(
            DEEPSEEK_URL,
            params={"text":q},
            timeout=60
        )
        r.raise_for_status()
        js = r.json()
        return js.get("answer_api","")
    except Exception as e:
        print(f"[警告] DeepSeek 调用失败：{e}")
        return ""

# ========= 初始化 Hugging Face QA Pipeline =========
print("正在加载 Hugging Face QA 模型……")
hf_qa = pipeline(
    "question-answering",
    model=HF_MODEL_NAME,
    tokenizer=HF_MODEL_NAME,
    device=0  # 无 GPU 时改成 -1
)

# ========= 主流程 =========
def main():
    data = load_data(DATA_PATH)
    # 只保留前 MAX_SAMPLES 条
    data = data[:MAX_SAMPLES]
    print(f"将测试前 {len(data)} 条样本。")

    d_base_ex, d_base_ap, d_ds, d_hf = [], [], [], []

    for item in tqdm(data, desc="Evaluating"):
        q, ctx, gold = item["question"], item["context"], item["answer"]

        # 1) Baseline
        ex, ap = call_baseline(q)
        d_base_ex.append(editdistance.eval(ex, gold))
        d_base_ap.append(editdistance.eval(ap, gold))

        # 2) DeepSeek
        ds = call_deepseek(q)
        d_ds.append(editdistance.eval(ds, gold))

        # 3) HF 大模型
        try:
            out = hf_qa(question=q, context=ctx)
            ans = out.get("answer","")
        except Exception as e:
            print(f"[警告] HF QA 出错：{e}")
            ans = ""
        d_hf.append(editdistance.eval(ans, gold))

    # 输出结果
    print("\n=== 平均 Levenshtein 距离 对比 (仅前{}条) ===".format(len(data)))
    print(f"Baseline Exact: {np.mean(d_base_ex):.2f}")
    print(f"Baseline App  : {np.mean(d_base_ap):.2f}")
    print(f"DeepSeek      : {np.mean(d_ds):.2f}")
    print(f"HF 大模型     : {np.mean(d_hf):.2f}")

if __name__ == "__main__":
    main()
