import numpy as np
from sklearn.preprocessing import PolynomialFeatures, StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import roc_curve, auc
import matplotlib.pyplot as plt

# 1) 加载数据
data2 = np.loadtxt('ex2data2.txt', delimiter=',')
X2, y2 = data2[:, :2], data2[:, 2]

# 2) 特征映射到多项式（degree=6）
poly = PolynomialFeatures(degree=6)
X2_poly = poly.fit_transform(X2)

# 3) 标准化
scaler = StandardScaler()
X2_scaled = scaler.fit_transform(X2_poly)

# 4) 正则化逻辑回归（λ=1 对应 C=1/λ=1）
model2 = LogisticRegression(C=1.0, solver='lbfgs', max_iter=500)
model2.fit(X2_scaled, y2)

# 5) 预测概率 & ROC
y2_prob = model2.predict_proba(X2_scaled)[:, 1]
fpr, tpr, thresholds = roc_curve(y2, y2_prob)
roc_auc = auc(fpr, tpr)

# 6) 绘制 ROC 曲线
plt.figure()
plt.plot(fpr, tpr, label=f'AUC = {roc_auc:.3f}')
plt.plot([0,1], [0,1], 'k--')
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('第二类问题 ROC 曲线')
plt.legend(loc='lower right')
plt.grid(True)
plt.show()

# 7) 输出 AUC 值
print(f"第二类问题 AUC = {roc_auc:.3f}")
