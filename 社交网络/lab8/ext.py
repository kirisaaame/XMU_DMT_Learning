import os
from pathlib import Path
from itertools import chain
from PIL import Image
import torch
from transformers import (
    BlipProcessor,
    BlipForConditionalGeneration,
    BlipForQuestionAnswering
)
import json

# 离线模式开关
os.environ["TRANSFORMERS_OFFLINE"] = "1"
os.environ["HF_HUB_OFFLINE"]       = "1"

ARCHIVE_ROOT = Path("archive")
IMAGE_DIRS   = [ARCHIVE_ROOT / f"images_{i:03d}" for i in range(1, 13)]
OUT_FILE     = Path("nih_vqa_dataset.jsonl")

# Snapshot 路径（示例，请替换为你的实际路径）
CAP_SNAPSHOT = "cache/blip_cap/models--Salesforce--blip-image-captioning-base/snapshots/82a37760796d32b1411fe092ab5d4e227313294b"
VQA_SNAPSHOT = "cache/blip_vqa/models--Salesforce--blip-vqa-base/snapshots/787b3d35d57e49572baabd22884b3d5a05acf072"

DEVICE       = "cuda" if torch.cuda.is_available() else "cpu"

# 加载模型
proc_cap = BlipProcessor.from_pretrained(CAP_SNAPSHOT, local_files_only=True, use_fast=True)
model_cap= BlipForConditionalGeneration.from_pretrained(CAP_SNAPSHOT, local_files_only=True).to(DEVICE)
proc_qa  = BlipProcessor.from_pretrained(VQA_SNAPSHOT, local_files_only=True, use_fast=True)
model_qa = BlipForQuestionAnswering.from_pretrained(VQA_SNAPSHOT, local_files_only=True).to(DEVICE)

QUESTIONS = [
    "Describe the main abnormality in this chest X-ray.",
    "Which lung region shows this abnormality?",
    "Is this suggestive of pneumonia?"
]

# 清空旧文件
if OUT_FILE.exists():
    OUT_FILE.unlink()

with open(OUT_FILE, "a", encoding="utf-8") as fout:
    # 遍历所有子文件夹下的 images 子目录
    for d in IMAGE_DIRS:
        sub = d / "images"
        if not sub.is_dir():
            print(f"跳过不存在目录：{sub}")
            continue

        for img_path in sorted(chain(sub.glob("*.png"),
                                     sub.glob("*.jpg"),
                                     sub.glob("*.jpeg"))):
            image = Image.open(img_path).convert("RGB")

            # 1. 生成 Caption
            cap_inputs = proc_cap(image, return_tensors="pt").to(DEVICE)
            cap_ids    = model_cap.generate(**cap_inputs, max_length=64)
            caption    = proc_cap.decode(cap_ids[0], skip_special_tokens=True)

            # 2. 生成 QA
            qas = []
            for q in QUESTIONS:
                qa_inputs = proc_qa(image, q, return_tensors="pt").to(DEVICE)
                out_ids   = model_qa.generate(**qa_inputs)
                ans       = proc_qa.batch_decode(out_ids, skip_special_tokens=True)[0]
                qas.append({"question": q, "answer": ans})

            # 3. 写入一行 JSONL
            record = {
                "image_id": img_path.relative_to(ARCHIVE_ROOT).as_posix(),
                "caption": caption,
                "qas": qas
            }
            fout.write(json.dumps(record, ensure_ascii=False) + "\n")

print(f"✅ 已追加写入所有记录到 {OUT_FILE}")
