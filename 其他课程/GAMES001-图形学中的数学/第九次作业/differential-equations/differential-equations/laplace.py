import numpy as np
import matplotlib.pyplot as plt
from utils import *
import os

os.makedirs('output', exist_ok=True)

resolution = 64
grid_size = (resolution, resolution)

u = np.zeros(grid_size)
boundary_value = [-1, 1, -1, 1]
u[0, 1:-1] = boundary_value[0]
u[1:-1, 0] = boundary_value[1]
u[-1, 1:-1] = boundary_value[2]
u[1:-1, -1] = boundary_value[3]

iters = 300
result = []
residual = 0
residual_init = compute_laplace_residual(u)

for iter in range(iters + 1):
    iter_jacobi(u)
    if iter % 60 == 0:
        residual = compute_laplace_residual(u)
        print("{:.3e}".format(residual / residual_init))
        result.append(u.copy())

fig, axes = plt.subplots(2, 3)
for i, ax in enumerate(axes.flatten()):
    ax.imshow(result[i], cmap='bwr', extent=[0, 1, 0, 1], origin='lower')
    ax.set_title('iter={}'.format(i * 60))
plt.tight_layout()
plt.savefig('output/laplace.png')