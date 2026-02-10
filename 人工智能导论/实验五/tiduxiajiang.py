import math

def f(x1, x2):
    """目标函数 f(x1,x2)."""
    return (
        4
        + 4.5*x1
        - 4*x2
        + x1**2
        + 2*x2**2
        - 2*x1*x2
        + x1**4
        - 2*(x1**2)*x2
    )

def grad(x1, x2):
    """计算梯度 (∂f/∂x1, ∂f/∂x2)."""
    g1 = 4.5 + 2*x1 - 2*x2 + 4*x1**3 - 4*x1*x2
    g2 = -4 + 4*x2 - 2*x1 - 2*x1**2
    return g1, g2

def gradient_descent(
    x1_init=-0.2,
    x2_init=2.5,
    learning_rate=0.1,
    max_iter=10
):
    x1, x2 = x1_init, x2_init
    for t in range(1, max_iter+1):
        y0 = f(x1, x2)
        g1, g2 = grad(x1, x2)
        norm = math.hypot(g1, g2)
        if norm == 0:
            print(f"第{t}次迭代梯度为零，停止迭代。")
            break

        # 沿归一化梯度方向更新
        x1_new = x1 - learning_rate * g1 / norm
        x2_new = x2 - learning_rate * g2 / norm
        y1 = f(x1_new, x2_new)

        # 接受更优解
        if y1 < y0:
            x1, x2 = x1_new, x2_new

        print(
            f"Iter {t:2d}: x1 = {x1:.6f}, "
            f"x2 = {x2:.6f}, f = {y0:.6f}"
        )

    print("\n优化结束。最优解：")
    print(f"x1 = {x1:.6f}, x2 = {x2:.6f}, f = {f(x1,x2):.6f}")

if __name__ == "__main__":
    gradient_descent()
