import numpy as np

# 定义适应度函数
def fitness_real(x):
    func = (4 - 2.1 * x[0]**2 + x[0]**4 / 3) * x[0]**2 + x[0] * x[1] + (4 * x[1]**2 - 4) * x[1]**2
    return -func + 10000

# 初始化种群
def initialize_population_real(pop_size, dim, min_val, max_val):
    return np.random.uniform(min_val, max_val, (pop_size, dim))

# 主程序
def ga_real(pop_size=50, dim=2, generations=100, pcross=0.6, pmutation=0.02):
    min_val, max_val = [-3, -2], [3, 2]
    population = initialize_population_real(pop_size, dim, min_val, max_val)
    best_solution = None
    best_fitness = -np.inf

    for _ in range(generations):
        fitness_values = np.array([fitness_real(ind) for ind in population])
        
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
best_x, best_fit = ga_real()
print(f"GA实数算法: 最优解 x = {best_x}, 最优适应度 = {best_fit}")