import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

# 1) 加载数据
data1 = np.loadtxt('ex2data1.txt', delimiter=',')
X1, y1 = data1[:, :2], data1[:, 2]

# 2) 训练逻辑回归（默认无正则化 C=1e12 ≈ 无约束）
model1 = LogisticRegression(C=1e12, solver='lbfgs', max_iter=400)
model1.fit(X1, y1)

# 3) 预测并评估
y1_pred = model1.predict(X1)
acc1 = accuracy_score(y1, y1_pred)
print(f"第一类问题训练集准确率：{acc1*100:.2f}%")
