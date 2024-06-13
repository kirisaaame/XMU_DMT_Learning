import numpy as np
import matplotlib.pyplot as plt
from utils import *
import os

os.makedirs('output', exist_ok=True)

coeff = 0.24
acceleration = lambda x, coeff = coeff: -coeff * x / (np.linalg.norm(x)**3)

position = np.array([0.3, 0])
velocity = np.array([0, -1])
trajectory = []
trajectory.append(position)

h = 0.05

for i in range(4000):
    for j in range(100):
        position, velocity = explicit_euler(position, velocity, acceleration, h / 100)
    trajectory.append(position)

plt.plot([x[0] for x in trajectory], [x[1] for x in trajectory], linewidth=0.3)
plt.gca().set_aspect('equal', adjustable='box')
plt.grid(True)
plt.xlim(-1, 0.5)
plt.ylim(-0.65, 0.65)
plt.savefig('output/explicit.png')
plt.cla()

position = np.array([0.3, 0])
velocity = np.array([0, -1])
trajectory = []
trajectory.append(position)

for i in range(4000):
    position, velocity = symplectic_euler(position, velocity, acceleration, h)
    trajectory.append(position)

plt.plot([x[0] for x in trajectory], [x[1] for x in trajectory], linewidth=0.3)
plt.gca().set_aspect('equal', adjustable='box')
plt.grid(True)
plt.xlim(-1, 0.5)
plt.ylim(-0.65, 0.65)
plt.savefig('output/symplectic_3.png')
