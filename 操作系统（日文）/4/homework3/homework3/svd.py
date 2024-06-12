import taichi as ti
import numpy as np
import pywavefront

ti.init(arch=ti.cpu)

scene = pywavefront.Wavefront('stanford-bunny.obj', collect_faces=True)
vertices = np.array(scene.vertices, dtype=np.float32)

vertices_num = vertices.shape[0]
rest_vertices = ti.Vector.field(3, dtype=ti.f32, shape=vertices.shape[0])
rest_vertices.from_numpy(vertices) # rest_vertices 存储了初始时刻粒子的位置，即集合 P

pause = True # pause 用于控制模拟的暂停和开始
cur_vertices = ti.Vector.field(3, ti.f32, vertices_num) # cur_vertices 存储了当前粒子的位置，即集合 Q
old_vertices = ti.Vector.field(3, ti.f32, vertices_num) # old_vertices 存储了上一时刻粒子的位置
velovity = ti.Vector.field(3, ti.f32, vertices_num) # velovity 存储了粒子的速度
rest_center = ti.Vector.field(3, ti.f32, ()) # 初始粒子的质心位置


@ti.func
def init_pos():
    for i in range(vertices_num):
        cur_vertices[i] = rest_vertices[i]
        old_vertices[i] = rest_vertices[i]
        velovity[i] = 0.0


@ti.func
def compute_center():
    cnt = 0
    center = ti.Vector([0.0, 0.0, 0.0])
    for i in range(vertices_num):
        cnt += 1
        center += cur_vertices[i]
    center /= cnt
    return center


@ti.kernel
def init():
    init_pos()
    rest_center[None] = compute_center()


@ti.kernel
def semi_euler(h: ti.f32):
    gravity = ti.Vector([0.0, -9.8, 0.0])
    for i in range(vertices_num):
        velovity[i] += h * gravity
        old_vertices[i] = cur_vertices[i]
        cur_vertices[i] += h * velovity[i]


@ti.kernel
def solve_constraints():
    # TODO: your code here
    # 请使用基于 SVD 的 shape matching 算法实现碰撞约束，具体来说，你需要根据 rest_vertices 和 cur_vertices 找到最优的旋转变换 R 和平移向量 t，然后就可以用下方的代码更新 cur_vertices
    raise NotImplementedError
    for i in range(vertices_num):
        target = R@rest_vertices[i] + t
        correct = (target - cur_vertices[i]) * 0.1
        cur_vertices[i] += correct

@ti.kernel
def collision_response():
    # 对于每个粒子，如果其位置的 y 坐标小于 -1.0，则将其位置设置为 -1.0
    for i in range(vertices_num):
        if cur_vertices[i][1] < -1.0:
            cur_vertices[i][1] = -1.0


@ti.kernel
def update_velocities(h: ti.f32):
    for i in range(vertices_num):
        velovity[i] = (cur_vertices[i] - old_vertices[i]) / h


def update(maxIte, h):
    semi_euler(h) # 使用半隐式欧拉法更新粒子的位置
    for i in range(maxIte): # 迭代多次确保求解稳定
        solve_constraints() # 使用 SVD 算法求解碰撞约束
        collision_response() # 处理碰撞
    update_velocities(h) # 更新粒子的速度


window = ti.ui.Window('Shape matching - Bunny', (800, 800))
scene = window.get_scene()
camera = ti.ui.make_camera()
camera.position(0.5, 1.5, 2.0)
camera.lookat(0.0, -0.25, 0.0)
camera.up(0.0, 1.0, 0.0)
camera.fov(30)
canvas = window.get_canvas()

init()
while window.running:
    # 按 r 重置模拟, 按 p 开始/暂停模拟
    if window.get_event(ti.ui.PRESS):
        if window.event.key == 'r': init()
        elif window.event.key == 'p': pause ^= 1
    if not pause:
        update(10, 0.01)
    scene.point_light((1.0, 1.0, 1.0), color=(1.0, 1.0, 1.0))
    scene.particles(cur_vertices, radius=0.005, color=(1.0, 0.0, 0.0))
    canvas.scene(scene)
    camera.track_user_inputs(window, movement_speed=0.03, hold_key=ti.ui.RMB)
    scene.set_camera(camera)
    window.show()