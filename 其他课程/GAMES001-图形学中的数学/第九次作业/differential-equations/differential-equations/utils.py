import numpy as np

def compute_laplace_residual(u):
    residual = 0
    grid_size = u.shape
    for i in range(1, grid_size[0]-1):
        for j in range(1, grid_size[1]-1):
            residual += (u[i-1, j] + u[i+1, j] + u[i, j-1] + u[i, j+1] - 4 * u[i, j]) ** 2
    return np.sqrt(residual)

def iter_jacobi(u):
    # TODO: your code here
    raise NotImplementedError

def explicit_euler(position, velocity, acceleration, dt):
    # TODO: your code here
    raise NotImplementedError

def symplectic_euler(position, velocity, acceleration, dt):
    # TODO: your code here
    raise NotImplementedError

def symplectic_euler_2(position, velocity, acceleration, dt):
    # TODO: your code here
    raise NotImplementedError

def symplectic_euler_3(position, velocity, acceleration, dt):
    # TODO: your code here
    raise NotImplementedError
