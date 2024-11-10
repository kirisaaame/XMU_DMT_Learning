# HW1

**Question 1:**
Suppose we have a two-player zero-sum game where each player has two actions, and the row payoff matrix is:

\[
\begin{bmatrix}
-\frac{1}{2} & \frac{3}{4} \\
1 & -\frac{3}{2}
\end{bmatrix}
\]

Compute the minimax optimal strategies of the row and column players and the value of the game.

**Choices:**

- [ ] 1. Row player: first action with \(\frac{2}{3}\), second action with \(\frac{1}{3}\); Column player: first action with \(\frac{3}{5}\), second action with \(\frac{2}{5}\); Value of the game: 0.

- [ ] 2. Row player: first action with \(\frac{1}{2}\), second action with \(\frac{1}{2}\); Column player: first action with \(\frac{1}{2}\), second action with \(\frac{1}{2}\); Value of the game: 0.

- [ ] 3. Row player: first action with \(\frac{1}{3}\), second action with \(\frac{2}{3}\); Column player: first action with \(\frac{2}{5}\), second action with \(\frac{3}{5}\); Value of the game: 1.

- [ ] 4. Row player: first action with \(\frac{3}{4}\), second action with \(\frac{1}{4}\); Column player: first action with \(\frac{1}{4}\), second action with \(\frac{3}{4}\); Value of the game: -1.

**Question 2:**

Consider the linear program: maximize \(8x + 6y\) subject to \(x + 2y \leq 6\), \(5x + 2y \leq 20\), and \(x, y \geq 0\). Calculate the optimal solution \((x, y)\).

**Choices:**

- [ ] 1. \(x = 3.5, y = 1.25\)

- [ ] 2. \(x = 4, y = 1\)

- [ ] 3. \(x = 2, y = 2\)

- [ ] 4. \(x = 3, y = 1.5\)

**Question3:**
True or False: The MG algorithm works in streams with additions and deletions.

**Choices:**

- [ ] T
- [ ] F

**Question4:**
True or False: If we run the MG algorithm with 1 counter and 1 memory cell and the counter is zero at the end of the stream, then there is no majority element.

**Choices:**

- [ ] T
- [ ] F

**Question5:**

Consider a stream of additions where one specific item occurs \( n^{1/2} \) times, and there are \( n - n^{1/2} - 1 \) other distinct items, each occurring once. In applying the Misra-Gries (MG) algorithm, which value of epsilon (\( \epsilon \)) should be chosen to ensure that the frequently occurring item is represented in one of our memory cells at the end of the stream?

**Choices:**

- [ ] A \( \epsilon = \frac{1}{n} \)
- [ ] B \( \epsilon = \frac{1}{n^{1/3}} \)
- [ ] C \( \epsilon = \frac{1}{n^{2/3}} \)
- [ ] D \( \epsilon = \frac{1}{n^{1/2}} \)

**Question6:**
In the worst case, how much time does it take to process one stream update
using the Misra-Gries (MG) algorithm with k memory cells and k counters?

**Choices:**

- [ ] A O(log k) time
- [ ] B O(k^2) time
- [ ] C O(1) time
- [ ] D O(k) time

**Question 7: Advanced Complexity Analysis in Non-uniform Recursive Linear Programming**
In a non-uniform recursive algorithm for linear programming, the division of the problem is not balanced. Instead, the larger subproblem at each step has a size that is a fixed fraction a (0 < a < 1) of the original problem, while the smaller subproblem has a size m - am, where m is the size of the current problem. Additionally, the work done at each step before the recursive calls is proportional to the square of the current problem size m^2. Assuming the algorithm converges to a single problem case in logarithmic steps with respect to the original problem size M, what is the time complexity of this algorithm?

- [ ] A O(M^2 log M)
- [ ] B O(M^2)
- [ ] C O(M^2 / (1-a))
- [ ] D O(M^(2+a))

**Question8:**
True or False: If Sigma = {1, ...n} then MG uses O((1/eps) log n) bits of memory on a stream of length n.

- [ ] T
- [ ] F
