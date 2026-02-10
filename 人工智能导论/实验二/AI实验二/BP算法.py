import numpy as np

ESC = 27
ERRORLEVEL = 0.02
ITEMS = 8

class BPNeuralNetwork:
    def __init__(self, eta=0.15, alpha=0.075, nReportErrors=100, ErrorLevel=ERRORLEVEL):
        self.eta = eta  # 学习速率
        self.alpha = alpha  # 动量因子
        self.nReportErrors = nReportErrors  # 误差报告频率
        self.ErrorLevel = ErrorLevel  # 误差阈值

    def load_data(self, run_file):
        with open(run_file, 'r') as f:
            self.nRuns = int(f.readline().strip())

            self.runs = []
            for _ in range(self.nRuns):
                data = f.readline().strip().split()
                self.runs.append({
                    'results_file': data[0],
                    'error_file': data[1],
                    'pattern_file': data[2],
                    'weights_file': data[3],
                    'weights_out_file': data[4],
                    'nPatterns': int(data[5]),
                    'nIterations': int(data[6]),
                    'nInputNodes': int(data[7]),
                    'nHiddenNodes': int(data[8]),
                    'nOutputNodes': int(data[9]),
                    'eta': float(data[10]),
                    'alpha': float(data[11]),
                })

    def initialize_weights(self, weights_file, nInputNodes, nHiddenNodes, nOutputNodes):
        with open(weights_file, 'r') as f:
            w1 = np.array([list(map(float, f.readline().strip().split())) for _ in range(nHiddenNodes)])
            w2 = np.array([list(map(float, f.readline().strip().split())) for _ in range(nOutputNodes)])
        return w1, w2

    def load_patterns(self, pattern_file, nPatterns, nInputNodes, nOutputNodes):
        with open(pattern_file, 'r') as f:
            data = [list(map(float, line.strip().split())) for line in f]
        
        patterns = np.array([row[:nInputNodes] for row in data])
        targets = np.array([row[nInputNodes:nInputNodes + nOutputNodes] for row in data])
        pattern_ids = np.array([row[-1] for row in data])

        return patterns, targets, pattern_ids

    def train(self, run_config):
        nPatterns = run_config['nPatterns']
        nInputNodes = run_config['nInputNodes']
        nHiddenNodes = run_config['nHiddenNodes']
        nOutputNodes = run_config['nOutputNodes']
        nIterations = run_config['nIterations']

        patterns, targets, pattern_ids = self.load_patterns(run_config['pattern_file'], nPatterns, nInputNodes, nOutputNodes)
        w1, w2 = self.initialize_weights(run_config['weights_file'], nInputNodes, nHiddenNodes, nOutputNodes)

        delw1 = np.zeros_like(w1)
        delw2 = np.zeros_like(w2)

        for iteration in range(nIterations):
            out1 = 1 / (1 + np.exp(-np.dot(patterns, w1.T)))  # 隐含层
            out2 = 1 / (1 + np.exp(-np.dot(out1, w2.T)))  # 输出层

            # 计算误差
            delta2 = (targets - out2) * out2 * (1 - out2)
            delta1 = np.dot(delta2, w2) * out1 * (1 - out1)

            # 更新权重
            delw2 = self.eta * np.dot(delta2.T, out1) + self.alpha * delw2
            delw1 = self.eta * np.dot(delta1.T, patterns) + self.alpha * delw1

            w2 += delw2
            w1 += delw1

            # 计算误差
            error = np.mean((targets - out2) ** 2)
            if iteration % self.nReportErrors == 0:
                print(f"Iteration {iteration}/{nIterations}, Error: {error:.6f}")
                with open(run_config['error_file'], 'a') as f:
                    f.write(f"{iteration} {error:.6f}\n")

            if error < self.ErrorLevel:
                break

        self.save_weights(run_config['weights_out_file'], w1, w2)
        self.save_results(run_config['results_file'], out2, pattern_ids)

    def save_weights(self, weights_out_file, w1, w2):
        with open(weights_out_file, 'w') as f:
            for row in w1:
                f.write(" ".join(map(str, row)) + "\n")
            for row in w2:
                f.write(" ".join(map(str, row)) + "\n")

    def save_results(self, results_file, out2, pattern_ids):
        with open(results_file, 'w') as f:
            for p, output in enumerate(out2):
                f.write(f"{p} {' '.join(map(str, output))} {pattern_ids[p]:.0f}\n")

    def run(self, run_file):
        self.load_data(run_file)
        for run_config in self.runs:
            print("Training...")
            self.train(run_config)

if __name__ == "__main__":
    bpnn = BPNeuralNetwork()
    bpnn.run("run_file.txt")  # 你需要提供一个包含训练配置的文件
