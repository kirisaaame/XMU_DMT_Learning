import numpy as np

# 定义适应度函数
def fitness_binary(x):
    return 0.5 - (np.sin(np.sqrt(x[0]**2 + x[1]**2))**2 - 0.5) / ((1 + 0.001 * (x[0]**2 + x[1]**2))**2)

# 初始化种群
def initialize_population_binary(pop_size, chrom_length):
    return np.random.randint(2, size=(pop_size, chrom_length))

# 解码二进制为实数
def decode_binary(chromosome, min_val, max_val):
    decimal = int("".join(map(str, chromosome)), 2)
    return min_val + decimal * (max_val - min_val) / (2**len(chromosome) - 1)

# 选择操作
def select(population, fitness_values):
    idx = np.random.choice(len(population), size=len(population), p=fitness_values/fitness_values.sum())
    return population[idx]

# 交叉操作
def crossover(parent1, parent2, pcross):
    if np.random.rand() < pcross:
        point = np.random.randint(1, len(parent1))
        return np.concatenate((parent1[:point], parent2[point:]))
    return parent1

# 变异操作
def mutate(chromosome, pmutation):
    for i in range(len(chromosome)):
        if np.random.rand() < pmutation:
            chromosome[i] = 1 - chromosome[i]
    return chromosome

# 主程序
def ga_binary(pop_size=50, chrom_length=10, generations=100, pcross=0.6, pmutation=0.03):
    population = initialize_population_binary(pop_size, chrom_length)
    min_val, max_val = -5, 5  # 搜索空间
    best_solution = None
    best_fitness = -np.inf

    for _ in range(generations):
        decoded_population = np.array([decode_binary(ind, min_val, max_val) for ind in population])
        fitness_values = np.array([fitness_binary([x, x]) for x in decoded_population])
        
        if fitness_values.max() > best_fitness:
            best_fitness = fitness_values.max()
            best_solution = population[fitness_values.argmax()]

        population = select(population, fitness_values)
        new_population = []
        for i in range(0, len(population), 2):
            parent1, parent2 = population[i], population[(i+1) % len(population)]
            child1 = crossover(parent1, parent2, pcross)
            child2 = crossover(parent2, parent1, pcross)
            new_population.append(mutate(child1, pmutation))
            new_population.append(mutate(child2, pmutation))
        population = np.array(new_population)

    return decode_binary(best_solution, min_val, max_val), best_fitness

# 运行算法
best_x, best_fit = ga_binary()
print(f"GA二进制算法: 最优解 x = {best_x}, 最优适应度 = {best_fit}")