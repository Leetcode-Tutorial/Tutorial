## 题目分析
编程找到第`n`个`ugly number`。  
`ugly number`的定义：
- 正整数
- 只由3个素数因子组成：`2, 3, 5`

例如，`1, 2, 3, 4, 5, 6, 8, 9, 10(2*5), 12(2*2*3)`是前`10`个`ugly number`。  
一般`1`被定义为`ugly number`。  
`11`不是一个`ugly number`，因为`11`由素数`11`组成。

## 题解
### 解题思路（1）
从`1`开始判断每一个数字是否是`ugly number`，直到找到第`n`个`ugly number`。  
判断一个数字是否是`ugly number`，可以由以下的程序实现：
```cpp
bool isUgly(int num) {
	if(num<=0) return false;
    while(num%2==0) num/=2;
    while(num%3==0) num/=3;
    while(num%5==0) num/=5;
    return num==1;
}
```
判断一个数字是否是`ugly number`，时间复杂度大致为`O(log(num))`，假如第`n`个`ugly number`是`num`,时间开销还是比较大的，在Online Judge上测试，超时。

### 解题思路（2）
由判断一个数字是否是`ugly number`的程序，我们可以得到一点启发：
- 若一个数字是`ugly number`，他一定能被`2, 3, 5`除尽。
- `num=12`，做除法`12/2=6, 6/2=3, 3/3=1`，我们反推除法过程`1*3=3, 3*2=6, 6*2=12`。
- 换句话，每一个`ugly number`都可以通过反复地乘以`2, 3, 5`得到。

既然是反复地做乘法，那就是递推的过程，也就是说，可以通过已有那些的`ugly number`，得到之后的`ugly number`，这是一种生成数字的过程，比判别数字是否是`ugly number`快了许多。  

我们希望顺序地生成`ugly number`，当生成到第`n`个`ugly number`，就完成了任务。  
- 第一个`ugly number`是`1`，由`1`生成的数字是`2, 3, 5`。  
- 所以第二个`ugly number`是`2`，由`2`生成的数字是`4, 6, 10`。  
- 我们发现第三个`ugly number`是`3`，而`4`是第四个`ugly number`。  

可见，想要顺序地生成`ugly number`，我们还要精心设计一下控制顺序的方法。  
要生成接下来的`ugly number`，之前的那些`ugly number`中的每一个都要乘以`2, 3, 5`，我们只要保证每一个`ugly number`都乘过这三个数即可。  
- `dp[i]`表示第`i+1`个`ugly number`。
- 设置三个指针`index_2, index_3, index_5`，分别指向`2, 3, 5`三个数字当前应该乘以哪个`ugly number`。
- `2*dp[index_2], 3*dp[index_3], 5*[index_5]`三个`ugly number`中最小的一个，就是下一个`ugly number`。
- 这个要生成的`ugly number`如果等于`2*dp[index_2], 3*dp[index_3], 5*[index_5]`中的某几个，那么对应的`index_x`就要加一，也就是指向下一个要乘以`x`的`ugly number`。

通过这种控制方式
- 保证了生成`ugly number`的顺序
- 不会重复生成同一个`ugly number`。  
- 不会遗漏任何`ugly number`。  

**算法复杂度**  
时间复杂度是`O(n)`，空间复杂度也是`O(n)`，具体实现在`solution.cpp`中。  
**例子**  
`n = 8`;  
`index_2 = 0; index_3 = 0; index_5 = 0`；  
`dp[0] = 1`  
- `dp[1]=min(2 * dp[index_2], 3 * dp[index_3], 5 * dp[index_5])=min(2, 3, 5)=2`;  
`index_2 = index_2 + 1 = 1`  
- `dp[2]=min(2 * dp[1], 3 * dp[0], 5 * dp[0]=min(4, 3, 5)=3`;  
`index_3 = 0 + 1 = 1`
- `dp[3]=min(2 * dp[1], 3 * dp[1], 5 * dp[0]=min(4, 6, 5)=4`;  
`index_2 = 1 + 1 = 2`
- `dp[4]=min(2 * dp[2], 3 * dp[1], 5 * dp[0]=min(6, 6, 5)=5`;  
`index_5 = 0 + 1 = 1`
- `dp[5]=min(2 * dp[2], 3 * dp[1], 5 * dp[1]=min(6, 6, 10)=6`;  
`index_2 = 2 + 1 = 3; index_3 = 1 + 1 = 2`
- `dp[6]=min(2 * dp[3], 3 * dp[2], 5 * dp[1]=min(8, 9, 10)=8`;  
`index_2 = 3 + 1 = 4`
- `dp[7]=min(2 * dp[4], 3 * dp[1], 5 * dp[1]=min(10, 9, 10)=9`;  
`index_3 = 1 + 1 = 2`

`8`个`ugly number`是`[1, 2, 3, 4, 5, 6, 8, 9]`。