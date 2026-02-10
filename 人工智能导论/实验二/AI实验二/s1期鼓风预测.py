import numpy as np
import pandas as pd

# **1. 设置参数**
InputNo = 3      # 输入节点数
OutputNo = 3     # 输出节点数
PatternNo = 358  # 训练样本数
HiddenNo = 10    # 隐藏层节点数
IterationsNo = 1000000  # 最大迭代次数
ErrorLevel = 0.005  # 误差阈值
eta = 0.1  # 学习速率
alpha = 0.1  # 动量因子
wmax = 0.1  # 权重初始化范围

# **2. 读取数据（单列存储）**
data = np.loadtxt("S1期鼓风操作数据.dat")  # 读取单列数据
data = data.reshape(PatternNo, InputNo + OutputNo)  # 变成 (358, 6)

# **3. 归一化数据**
x = data[:, :InputNo]  # 取前3列作为输入
y = data[:, InputNo:]  # 取后3列作为输出

x_mean = np.mean(x, axis=0)
x_std = np.std(x, axis=0)
x_norm = (x - x_mean) / x_std  # Z-score 标准化

y_mean = np.mean(y, axis=0)
y_std = np.std(y, axis=0)
y_norm = (y - y_mean) / y_std  # Z-score 标准化

# **4. 初始化权重**
w1 = np.random.uniform(-wmax, wmax, (HiddenNo, InputNo + 1))
w2 = np.random.uniform(-wmax, wmax, (OutputNo, HiddenNo + 1))
delw1 = np.zeros_like(w1)
delw2 = np.zeros_like(w2)

# **5. 训练 BP 神经网络**
for iteration in range(IterationsNo):
    total_error = 0

    for p in range(PatternNo):
        # **前向传播**
        in_hidden = np.dot(w1[:, :-1], x_norm[p]) + w1[:, -1]
        out_hidden = 1.0 / (1.0 + np.exp(-in_hidden))  # Sigmoid 激活

        in_output = np.dot(w2[:, :-1], out_hidden) + w2[:, -1]
        out_output = 1.0 / (1.0 + np.exp(-in_output))  # Sigmoid 激活

        # **计算误差**
        error = y_norm[p] - out_output
        total_error += np.sum(error ** 2)

        # **BP 误差传播**
        delta_output = error * out_output * (1.0 - out_output)
        delta_hidden = np.dot(w2[:, :-1].T, delta_output) * out_hidden * (1.0 - out_hidden)

        # **更新权重**
        delw2[:, :-1] = eta * np.outer(delta_output, out_hidden) + alpha * delw2[:, :-1]
        delw2[:, -1] = eta * delta_output + alpha * delw2[:, -1]
        w2 += delw2

        delw1[:, :-1] = eta * np.outer(delta_hidden, x_norm[p]) + alpha * delw1[:, :-1]
        delw1[:, -1] = eta * delta_hidden + alpha * delw1[:, -1]
        w1 += delw1

    # **计算均方误差（MSE）**
    mse = total_error / (PatternNo * OutputNo)
    if iteration % 10000 == 0:
        print(f"Iteration {iteration}/{IterationsNo}, Error: {mse:.6f}")

    # **误差满足要求，提前停止**
    if mse < ErrorLevel:
        print(f"训练提前终止：第 {iteration} 次迭代，误差 = {mse:.6f}")
        break

# **6. 预测**
predictions = []
for p in range(PatternNo):
    in_hidden = np.dot(w1[:, :-1], x_norm[p]) + w1[:, -1]
    out_hidden = 1.0 / (1.0 + np.exp(-in_hidden))

    in_output = np.dot(w2[:, :-1], out_hidden) + w2[:, -1]
    out_output = 1.0 / (1.0 + np.exp(-in_output))

    # **反标准化**
    y_pred = out_output * y_std + y_mean

    # **计算误差百分比，避免除以零**
    error_percent = np.abs((y[p] - y_pred) / np.where(y[p] != 0, y[p], 1)) * 100

    predictions.append([p, *y_pred, *y[p], *error_percent])

# **7. 保存结果**
df = pd.DataFrame(predictions, columns=["样本", "预测值1", "预测值2", "预测值3", "真实值1", "真实值2", "真实值3", "误差%1", "误差%2", "误差%3"])
df.to_csv("BP预测结果.csv", index=False, encoding="utf-8-sig")

print("\n训练完成，结果已保存至 BP预测结果.csv")