### 题目分析
**中文描述**  
只有 `0` 和 `1` 的二维矩阵，找出只包含 `1` 的最大矩形，返回最大矩形的面积。  
举个例子，以下矩阵 `matrix`  
```cpp
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```
最大的矩形是`matrix[1...2][2...4]`, 所以返回 6。  

### 题解
#### 解题思路（1）
这个问题和 [Largest Rectangle in Histogram](http://oj.leetcode.com/problems/largest-rectangle-in-histogram/) 很相似，具体实现在 `solution1.cpp` 中。  
可以使用一个数组 `heights` 记录 `matrix` 数组以某一行为底，从这一行开始某一列的连续 `1` 的数量，具体地：  
- 对每一行来说，若 `matrix[row][i] == 1`,`heights[i] += 1`;
- 否则，`heights[i] = 0`。

直接使用 [Largest Rectangle in Histogram](http://oj.leetcode.com/problems/largest-rectangle-in-histogram/) 的算法来计算以每一行为底的最大矩形的面积：
- 从第一行开始计算，一直计算到最后一行，以每一行的结果更新最大面积。

**算法复杂度**  
若二维数组有 `m` 行 `n` 列：
- 那么计算以某一行为底的最大面积，时间复杂度就是 [Largest Rectangle in Histogram](http://oj.leetcode.com/problems/largest-rectangle-in-histogram/) 的时间复杂度 `O(n)`；
- 一共有 `m` 行，整体的时间复杂度是 `O(m * n)`；
- 空间复杂度就是 [Largest Rectangle in Histogram](http://oj.leetcode.com/problems/largest-rectangle-in-histogram/) 的空间复杂度 `O(n)`。

#### 解题思路（2）
另一个解题方式就是使用动态规划（DP），具体实现在 `solution2.cpp` 中。  
由于要找的是一个矩形，因此对于二维数组中的每一个 `1` 元素，我们以这个 `1` 元素向上连续的 `1` 的数量为矩形的高度，向这个 `1` 元素的左右两侧扩展，就可以得到以这个 `1` 元素为核心的矩形的面积。  
**记录以某个元素为核心的矩形的高度**  
每一行内的 `1` 元素能达到的高度可以由前一行得到，高度数组为 `heights[m][n]`：
- 若 `matrix[i][j] == '0'`，`heights[i][j] = 0`；
- 若 `matrix[i][j] == '1'`，`heights[i][j] = heights[i-1][j] + 1`。  

**记录以某个元素为核心的矩形的宽度**  
每一行内的 `1` 元素能达到的宽度也由前一行和当前行共同决定，这里的宽度我们用两个数组来记录 `lefts[m][n] 和 rights[m][n]`，某一个 `1` 元素的宽度等于 `rights[i][j] - lefts[i][j]`：
- 我们已经知道了前一行的 `lefts 和 rights` 数组，假设当前行的元素全部为 `1`，那么：
`lefts[i][j] = lefts[i-1][j]`  
`rights[i][j] = rights[i-1][j]`  
- 可见当前行中的 `1` 元素能达到的宽度取决于本行的元素分布情况：
如果当前行的某个位置出现了 `0` 元素，上面的状态转移方程就要改变，我们使用变量 `cur_left` 记录元素左边界的变化情况，使用变量 `cur_right` 记录元素右边界的变化情况。
- 先从左向右扫描当前行来更新 `lefts` 数组，若当前元素 `j` 为 `0`,`lefts[i][j] = 0`，`cur_left = j + 1`;  
若当前元素 `j` 为 `1`,`lefts[i][j] = max(lefts[i-1][j], cur_left)`。
- 再从左向右扫描当前行来更新 `rights` 数组，若当前元素 `j` 为 `0`,`rights[i][j] = n`，`cur_right = j`;  
若当前元素 `j` 为 `1`,`rights[i][j] = min(rights[i-1][j], cur_right)`。  

*说明*  
为什么当前元素 `j` 为 `0`时,`lefts[i][j]` 要赋值为 `0`：
- 当前行的元素 `j` 为 `0`，代表着下一行的元素 `j` 的高度 `heights[i+1][j] <= 1`，那么下一行的元素 `j` 所能达到的左边界就只受下一行影响，而与当前行无关，我们把 `lefts[i][j]` 赋值为 `0` 的目的就是要消除当前行对下一行的元素 `j` 左边界的影响。  

为什么当前元素 `j` 为 `0`时,`rights[i][j]` 要赋值为 `n`：
- 同理，我们把 `rights[i][j]` 赋值为 `n`的目的就是要消除当前行对下一行的元素 `j` 右边界的影响。  

**计算以某个元素为核心的矩形的面积**  
对于某个元素，它的面积计算公式是 `area = heights[i][j] * (lefts[i][j] - rights[i][j])`。  

**算法整体流程**  
由于 `heights`、`lefts` 和 `rights` 三个数组的更新只跟前一行有关，因此我们可以用三个一维数组来记录它们，维护矩形最大值变量 `max_area`。  
开始的时候 `heights` 和 `lefts` 数组全部赋值为 `0`，`rights` 数组赋值为 `n`。  
从第一行开始向最后一行扫描，对于每一行执行如下操作：
- 从左向右（从右向左也行）计算以每个元素为核心的矩形的高度；
- 从左向右计算以某个元素为核心的矩形的左边界；
- 从右向左计算以某个元素为核心的矩形的右边界；
- 从左向右（从右向左也行）计算以每个元素为核心的矩形的面积, 更新 `max_area`。  

**算法复杂度**  
对数组每一行的四个操作（计算高度、左边界、右边界和面积）的时间复杂度都是 `O(n)`，则整体的时间复杂度是 `O(m * n)`。  
空间复杂度就是三个状态数组 `O(n)`。  

**举个例子**  
```cpp
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```
开始时，`heights=[0,0,0,0,0]`, `lefts=[0,0,0,0,0]`, `rights=[5,5,5,5,5]`。  
- `cur_left = 0`, `cur_right = 5`，处理完第 `0` 行之后：  
`cur_left = 5`, `cur_right = 1`；  
`heights=[1,0,1,0,0]`, `lefts=[0,0,2,0,0]`, `rights=[1,5,3,5,5]`；  
相应位置的面积 `area=[1,0,1,0,0]`;  

- `cur_left = 0`, `cur_right = 5`，处理完第 `1` 行之后：  
`cur_left = 2`, `cur_right = 1`；  
`heights=[2,0,2,1,1]`, `lefts=[0,0,2,2,2]`, `rights=[1,5,3,5,5]`；  
相应位置的面积 `area=[2,0,2,3,3]`;  

- `cur_left = 0`, `cur_right = 5`，处理完第 `2` 行之后：  
`cur_left = 0`, `cur_right = 5`；  
`heights=[3,1,3,2,2]`, `lefts=[0,0,2,2,2]`, `rights=[1,5,3,5,5]`；  
相应位置的面积 `area=[3,5,3,6,6]`;  

- `cur_left = 0`, `cur_right = 5`，处理完第 `3` 行之后：  
`cur_left = 5`, `cur_right = 1`；  
`heights=[4,0,0,3,0]`, `lefts=[0,0,0,3,0]`, `rights=[1,5,5,4,5]`；  
相应位置的面积 `area=[4,0,0,3,0]`;  