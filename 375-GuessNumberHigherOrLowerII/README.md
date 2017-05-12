## 题目分析
一个游戏叫做`Guess Game`，规则如下：
- 我从`1`到`n`中取一个整数，玩家要猜我取的是哪个整数
- 如果玩家猜错了，我会告诉玩家猜大了还是猜小了
- 当玩家猜的数字是`x`，并且猜错了，会有`$x`的惩罚
- 直到玩家猜到了我取的数字，游戏结束

```cpp
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
```
给定`n >= 1`，找出无论我取哪个数字，游戏结束时，玩家最少要付多少钱。

## 题解
### 解题思路（1）
要得到一个整数序列`[i...j]`的最少惩罚`DP([i...j])`
- 可以枚举第一次猜某个数`x`，`pick[x] = x + max( DP([i...x-1]), DP([x+1...j]) )`
- `DP([i...j]) = min{ pick[x] | i <= x <= j }`

可以看出我们可以使用分治的思想来解决问题
```cpp
public class Solution {
    public int getMoneyAmount(int n) {
        int[][] table = new int[n+1][n+1];
        return DP(table, 1, n);
    }
    
    int DP(int[][] t, int s, int e){
        if(s >= e) return 0;
        if(t[s][e] != 0) return t[s][e];
        int res = Integer.MAX_VALUE;
        for(int x=s; x<=e; x++){
            int tmp = x + Math.max( DP(t, s, x-1), DP(t, x+1, e) );
            res = Math.min(res, tmp);
        }
        t[s][e] = res;
        return res;
    }
}
```

### 解题思路（2）
分治算法对应的从底至上的动态规划方法如下，具体实现在`solution.cpp`中。  
当计算`DP([i...j])`时要知道`DP([i...x-1]) 和 DP([x+1...j]), i <= x <= j`  
我们可以先计算长度小于`l`的整数数列的最少惩罚，这样的话就可以计算长度为`l`的整数序列的最少惩罚了，流程如下。  
```cpp
	int min_sum[n+1][n+1]
    // iterate the length of subarray
    for (int l = 1; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++){
            int j = i + l - 1;
            Calculate min_sum[i][j]
        }
    return min_sum[1][n];
```
**时间复杂度**  
三重循环：枚举序列长度，枚举序列开始位置，枚举第一次猜对应序列中的哪个数。  
所以时间复杂度为`O(n^3)`，空间复杂度为`O(n^2)`。