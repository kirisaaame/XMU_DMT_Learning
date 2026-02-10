import numpy as np

# 定义适应度函数
def fitness_test(y):
    u = np.pi * y[0] * 1000 / 60
    cz = 200 / (y[0]**2 * (1 - y[1]**2) * np.pi)
    dcu = 980 / (1.26 * u * 0.8)
    wm = np.sqrt(cz**2 + (u - dcu / 2)**2)
    b = 117600 / (y[3] * y[2] * 1.26 * 800 * wm)
    cx = 0.022 - 0.006 * np.pi * y[0] / y[2] / b + 0.018 * y[3]**2 + 0.02 * 2 * np.pi / (y[2] * (1 - y[1]))
    func1 = 1 - cx / y[3] * wm**2 / (u * cz) - 0.1 * y[1]**2 * (2 - y[1]**2) * cz**2 / (u * dcu)
    func2 = 56 * np.log(u) + 10 * np.log(980 * y[0] * (1 - y[1]) * y[2] * np.sqrt(b) / 2)
    return 100 * func1 - func2 + 200

# 初始化种群
def initialize_population_test(pop_size, dim, min_val, max_val):
    return np.random.uniform(min_val, max_val, (pop_size, dim))

# 主程序
def ga_test(pop_size=50, dim=4, generations=100, pcross=0.6, pmutation=0.02):
    min_val, max_val = [0.1, 0.1, 0.1, 0.1], [10, 1, 10, 2]
    population = initialize_population_test(pop_size, dim, min_val, max_val)
    best_solution = None
    best_fitness = -np.inf

    for _ in range(generations):
        fitness_values = np.array([fitness_test(ind) for ind in population])
        
        if fitness_values.max() > best_fitness:
            best_fitness = fitness_values.max()
            best_solution = population[fitness_values.argmax()]

        # 选择、交叉、变异
        selected = population[np.random.choice(pop_size, size=pop_size, p=fitness_values/fitness_values.sum())]
        new_population = []
        for i in range(0, pop_size, 2):
            parent1, parent2 = selected[i], selected[(i+1) % pop_size]
            if np.random.rand() < pcross:
                point = np.random.randint(1, dim)
                child1 = np.concatenate((parent1[:point], parent2[point:]))
                child2 = np.concatenate((parent2[:point], parent1[point:]))
            else:
                child1, child2 = parent1, parent2
            new_population.append(child1 + np.random.uniform(-pmutation, pmutation, dim))
            new_population.append(child2 + np.random.uniform(-pmutation, pmutation, dim))
        population = np.clip(new_population, min_val, max_val)

    return best_solution, best_fitness

# 运行算法
best_y, best_fit = ga_test()
print(f"GA检验算法: 最优解 y = {best_y}, 最优适应度 = {best_fit}")