import cv2
import numpy as np
import mediapipe as mp

mp_holistic = mp.solutions.holistic
mp_drawing  = mp.solutions.drawing_utils

def extract_landmarks(results):
    if not (results.pose_landmarks and
            results.left_hand_landmarks and
            results.right_hand_landmarks):
        return None
    pts = []
    for lm in results.pose_landmarks.landmark:
        pts += [lm.x, lm.y]
    for lm in results.left_hand_landmarks.landmark:
        pts += [lm.x, lm.y]
    for lm in results.right_hand_landmarks.landmark:
        pts += [lm.x, lm.y]
    return np.array(pts, dtype=np.float32)

def load_reference_seq(ref_path):
    cap = cv2.VideoCapture(ref_path)
    seq = []
    with mp_holistic.Holistic(
            min_detection_confidence=0.5,
            min_tracking_confidence=0.5
        ) as holistic:
        while True:
            ret, frame = cap.read()
            if not ret:
                break
            img = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            res = holistic.process(img)
            lm = extract_landmarks(res)
            if lm is not None:
                seq.append(lm)
    cap.release()
    return seq

def stack_and_resize(left, right, size=(640,480)):
    left_s  = cv2.resize(left,  size)
    right_s = cv2.resize(right, size)
    return np.hstack((left_s, right_s))

def main(ref_video, threshold=0.15, cam_idx=0):
    # 预加载参考动作关键点
    ref_seq = load_reference_seq(ref_video)

    cap_ref = cv2.VideoCapture(ref_video)
    # 获取参考视频帧率，用于计算延迟
    fps = cap_ref.get(cv2.CAP_PROP_FPS) or 30
    delay_normal = int(1000 / fps)          # 正常速度延迟（ms）
    delay_slow   = delay_normal * 4         # 0.25×慢速

    cap_cam = cv2.VideoCapture(cam_idx, cv2.CAP_DSHOW)
    if not cap_cam.isOpened():
        print("ERROR: 无法打开摄像头")
        return

    # 首帧提示
    ret, first_ref = cap_ref.read()
    if not ret:
        print("ERROR: 读取参考视频失败")
        return
    last_ref = first_ref.copy()

    prompt = cv2.resize(first_ref, (640,480))
    cv2.putText(prompt, "Press 's' to START | 'l' Slow | 'r' Restart",
                (10,460), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0,255,255), 2)
    cv2.imshow('Reference Frame', prompt)

    # 等待用户按 s 开始
    while True:
        k = cv2.waitKey(0) & 0xFF
        if k in (ord('s'), ord('S')):
            cv2.destroyWindow('Reference Frame')
            break

    # 可缩放窗口
    win = 'Reference (L) | Feedback (R)'
    cv2.namedWindow(win, cv2.WINDOW_NORMAL)
    cv2.resizeWindow(win, 1280, 480)

    idx = 0
    slow_mode = False
    with mp_holistic.Holistic(
            min_detection_confidence=0.5,
            min_tracking_confidence=0.5
        ) as holistic:

        while True:
            # 读帧
            ret_r, frame_ref = cap_ref.read()
            ret_c, frame_cam = cap_cam.read()
            if not ret_c:
                print(">> 摄像头流结束，退出")
                break

            # 重启逻辑由后面按键处理
            # 冻结参考视频最后一帧
            if ret_r:
                last_ref = frame_ref.copy()
            else:
                frame_ref = last_ref

            # 姿态检测
            img = cv2.cvtColor(frame_cam, cv2.COLOR_BGR2RGB)
            res = holistic.process(img)
            user_lm = extract_landmarks(res)

            # 反馈画面标注
            disp = frame_cam.copy()
            if user_lm is not None and idx < len(ref_seq):
                diffs = np.abs(user_lm - ref_seq[idx]).reshape(-1,2)
                pts   = user_lm.reshape(-1,2)
                for i, (dx, dy) in enumerate(diffs):
                    x = int(pts[i][0] * disp.shape[1])
                    y = int(pts[i][1] * disp.shape[0])
                    color = (255,0,0) if dx+dy <= threshold else (0,0,255)
                    cv2.circle(disp, (x,y), 5, color, -1)

            # 拼接并显示
            out = stack_and_resize(frame_ref, disp, size=(640,480))
            cv2.imshow(win, out)

            idx += 1

            # 根据模式切换延迟
            delay = delay_slow if slow_mode else delay_normal
            key = cv2.waitKey(delay) & 0xFF

            if key == 27:          # Esc 清退出
                break
            elif key in (ord('l'), ord('L')):    # 切换慢速
                slow_mode = not slow_mode
                mode = "0.25x" if slow_mode else "1x"
                print(f">> Slow mode: {mode}")
            elif key in (ord('r'), ord('R')):    # 重新开始
                cap_ref.set(cv2.CAP_PROP_POS_FRAMES, 0)
                idx = 0
                print(">> Restarted reference video")
                # 立刻读取首帧以刷新 last_ref
                ret0, f0 = cap_ref.read()
                if ret0:
                    last_ref = f0.copy()

    cap_ref.release()
    cap_cam.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main(r'ref.mp4')
