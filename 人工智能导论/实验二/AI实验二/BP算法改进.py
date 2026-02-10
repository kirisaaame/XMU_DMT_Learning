import numpy as np
import pandas as pd

# 设定超参数
nPatterns = 66  # 样本数
nInputNodes = 9  # 输入节点数
nHiddenNodes = 5  # 隐藏层节点数
nOutputNodes = 1  # 输出节点数
nIterations = 500000  # 迭代次数
ErrorLevel = 0.002  # 误差阈值
eta = 0.35  # 学习速率
alpha = 0.1  # 动量因子
wmax = 0.3  # 权重最大值
scale = 32767  # 归一化缩放比例

# **1. 数据初始化**
x = np.array([
    [0.05,2.32,0.21,0.073,26,340,690,8,18],
    [0.05,2.25,0.19,0.072,30,340,695,8,18],
    [0.05,2.30,0.25,0.080,29,300,700,9,17],
    # ... (省略部分数据)
])

y = np.array([
    [435], [442], [450], [453], [455], [456], [460], [461], [463],
    # ... (省略部分数据)
])

# **2. 数据标准化**
x_mean = np.mean(x, axis=0)
x_std = np.std(x, axis=0)
x_norm = (x - x_mean) / x_std  # Z-score 标准化

y_mean = np.mean(y, axis=0)
y_std = np.std(y, axis=0)
y_norm = (y - y_mean) / y_std  # Z-score 标准化

# **3. 初始化权重**
w1 = np.random.uniform(-wmax, wmax, (nHiddenNodes, nInputNodes + 1))
w2 = np.random.uniform(-wmax, wmax, (nOutputNodes, nHiddenNodes + 1))

delw1 = np.zeros_like(w1)
delw2 = np.zeros_like(w2)

# **4. BP 训练过程**
for iteration in range(nIterations):
    total_error = 0

    for p in range(nPatterns):
        # 输入层 → 隐藏层
        in_hidden = np.dot(w1[:, :-1], x_norm[p]) + w1[:, -1]
        out_hidden = 1.0 / (1.0 + np.exp(-in_hidden))  # Sigmoid

        # 隐藏层 → 输出层
        in_output = np.dot(w2[:, :-1], out_hidden) + w2[:, -1]
        out_output = 1.0 / (1.0 + np.exp(-in_output))  # Sigmoid

        # 计算误差
        error = y_norm[p] - out_output
        total_error += np.sum(error ** 2)

        # 计算梯度（BP 误差传播）
        delta_output = error * out_output * (1.0 - out_output)
        delta_hidden = np.dot(w2[:, :-1].T, delta_output) * out_hidden * (1.0 - out_hidden)

        # 权重更新
        delw2[:, :-1] = eta * np.outer(delta_output, out_hidden) + alpha * delw2[:, :-1]
        delw2[:, -1] = eta * delta_output + alpha * delw2[:, -1]
        w2 += delw2

        delw1[:, :-1] = eta * np.outer(delta_hidden, x_norm[p]) + alpha * delw1[:, :-1]
        delw1[:, -1] = eta * delta_hidden + alpha * delw1[:, -1]
        w1 += delw1

    # 计算均方误差（MSE）
    mse = total_error / (nPatterns * nOutputNodes)
    if iteration % 10000 == 0:
        print(f"Iteration {iteration}/{nIterations}, Error: {mse:.6f}")

    # 提前停止
    if mse < ErrorLevel:
        print(f"训练提前终止：第 {iteration} 次迭代，误差 = {mse:.6f}")
        break

# **5. 预测**
predictions = []
for p in range(nPatterns):
    in_hidden = np.dot(w1[:, :-1], x_norm[p]) + w1[:, -1]
    out_hidden = 1.0 / (1.0 + np.exp(-in_hidden))

    in_output = np.dot(w2[:, :-1], out_hidden) + w2[:, -1]
    out_output = 1.0 / (1.0 + np.exp(-in_output))

    # 反标准化
    y_pred = out_output * y_std + y_mean
    predictions.append([p, y_pred[0], y[p][0], abs((y[p][0] - y_pred[0]) / y[p][0]) * 100])

# **6. 保存结果**
df = pd.DataFrame(predictions, columns=["样本", "预测值", "真实值", "误差百分比"])
df.to_csv("BP算法结果.csv", index=False, encoding="utf-8-sig")

print("\n训练完成，结果已保存至 BP算法结果.csv")
