import pygame
import heapq

# 初始化
pygame.init()

# 参数设置
grid_size = 20
cols, rows = 30, 20
screen = pygame.display.set_mode((cols * grid_size, rows * grid_size))
pygame.display.set_caption("A* Pathfinding Visualizer")

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
GRAY = (200, 200, 200)

# 地图：0为可通行，1为障碍
grid = [[0 for _ in range(cols)] for _ in range(rows)]

start = None
end = None
path = []

# 启发函数（曼哈顿距离）
def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

# 获取相邻节点（含对角线）
def get_neighbors(pos):
    x, y = pos
    directions = [
        (-1, 0), (1, 0), (0, -1), (0, 1),
        (-1, -1), (-1, 1), (1, -1), (1, 1)
    ]
    neighbors = []
    for dx, dy in directions:
        nx, ny = x + dx, y + dy
        if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] == 0:
            neighbors.append((nx, ny))
    return neighbors

# A* 算法
def a_star(start, end):
    open_set = []
    heapq.heappush(open_set, (0, start))
    came_from = {}
    g_score = {start: 0}
    f_score = {start: heuristic(start, end)}

    while open_set:
        _, current = heapq.heappop(open_set)

        if current == end:
            return reconstruct_path(came_from, current)

        for neighbor in get_neighbors(current):
            tentative_g = g_score[current] + 1
            if tentative_g < g_score.get(neighbor, float('inf')):
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g
                f_score[neighbor] = tentative_g + heuristic(neighbor, end)
                heapq.heappush(open_set, (f_score[neighbor], neighbor))

    return []

# 回溯路径
def reconstruct_path(came_from, current):
    path = [current]
    while current in came_from:
        current = came_from[current]
        path.append(current)
    path.reverse()
    return path

# 绘图函数
def draw():
    screen.fill(WHITE)
    for i in range(rows):
        for j in range(cols):
            rect = pygame.Rect(j * grid_size, i * grid_size, grid_size, grid_size)
            if grid[i][j] == 1:
                pygame.draw.rect(screen, BLACK, rect)
            elif (i, j) in path:
                pygame.draw.rect(screen, BLUE, rect)
            elif (i, j) == start:
                pygame.draw.rect(screen, GREEN, rect)
            elif (i, j) == end:
                pygame.draw.rect(screen, RED, rect)
            pygame.draw.rect(screen, GRAY, rect, 1)
    pygame.display.flip()

# 主循环
running = True
while running:
    draw()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if pygame.mouse.get_pressed()[0]:  # 左键设置起点/终点/障碍
            x, y = pygame.mouse.get_pos()
            row, col = y // grid_size, x // grid_size
            if not start:
                start = (row, col)
            elif not end and (row, col) != start:
                end = (row, col)
            elif (row, col) != start and (row, col) != end:
                grid[row][col] = 1

        if pygame.mouse.get_pressed()[2]:  # 右键清除
            x, y = pygame.mouse.get_pos()
            row, col = y // grid_size, x // grid_size
            if (row, col) == start:
                start = None
            elif (row, col) == end:
                end = None
            else:
                grid[row][col] = 0

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and start and end:
                path = a_star(start, end)
            if event.key == pygame.K_c:
                start = None
                end = None
                grid = [[0 for _ in range(cols)] for _ in range(rows)]
                path = []

pygame.quit()
