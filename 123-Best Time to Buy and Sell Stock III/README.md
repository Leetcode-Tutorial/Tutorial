## 题目分析：
给你一种股票每天的交易价格，在这些天中最多可以进行两次购买和两次卖出的交易，但在同一时间内不能同时涉及两次交易（即第二次买之前必须把第一次买的卖掉），问最大收益是多少。

### 解题思路（1）：
暴力枚举交易一次、交易两次的所有可能情况。这种方法时间复杂度为O(n^4)，天数稍微多一点就无法接受。

### 解题思路（2）：
动态规划。用dp[i]表示前i天最多只交易一次所获得的最大收益，并用一个变量minm记录最小的价格，假设第i天的股票价格在prices[i-1]中，则有转移方程dp[i]=max(dp[i-1],prices[i-1]-minm)，然后更新minm=min(minm,prices[i-1])，这样从前往后扫一遍即可。然后需要考虑第二次交易的情况，用ans表示最终答案，maxm记录最大的价格，对数组从后往前扫，更新ans=max(ans,dp[i]+maxm-prices[i-1])，然后更新maxm=max(maxm,prices[i-1])。初始时，dp[0]设为0，minm设为极大值；然后更新完dp数组后，maxm设为极小值，ans设为dp[n]。最后答案为ans，时间复杂度为O(n)。

#### 算法正确性：
算法的关键点在于上述过程能否保证正确考虑到所有可能的情况。首先在计算dp数组时，如果始终没有出现当前价格比最小价格大的情况，就说明不需要进行交易，整个dp数组就都是0，第二遍往回扫的时候ans也始终会是0。然后在往回扫的时候，maxm保存的是当前天数后面的最高价，更新的时候dp[i]为前i天交易一次的情况，maxm-prices[i-1]是第i天开始交易一次的情况，这样就保证了两次交易不交叉，另外如果ans始终不更新，保存的就是只交易一次的最大收益。因此上述算法是正确的。

下面举一个简单例子走一遍算法帮助理解：[3,5,4,7,1,3]。</br>
从前往后扫：</br>
初始化：dp[0]=0，minm=1e9+7；</br>
第一天：dp[1]=max(dp[0],prices[0]-minm)=0，minm=min(minm,prices[0])=3；</br>
第二天：dp[2]=max(dp[1],prices[1]-minm)=2，minm=min(minm,prices[1])=3；</br>
第三天：dp[3]=max(dp[2],prices[2]-minm)=2，minm=min(minm,prices[2])=3；</br>
第四天：dp[4]=max(dp[3],prices[3]-minm)=4，minm=min(minm,prices[3])=3；</br>
第五天：dp[5]=max(dp[4],prices[4]-minm)=4，minm=min(minm,prices[4])=1；</br>
第六天：dp[6]=max(dp[5],prices[5]-minm)=4，minm=min(minm,prices[5])=1；</br>
从后往前扫：</br>
初始化：ans=dp[6]=4，maxm=-1；</br>
第六天：ans=max(ans,dp[6]+maxm-prices[5])=4，maxm=max(maxm,prices[5])=3；</br>
第五天：ans=max(ans,dp[5]+maxm-prices[4])=6，maxm=max(maxm,prices[4])=3；</br>
第四天：ans=max(ans,dp[4]+maxm-prices[3])=6，maxm=max(maxm,prices[3])=7；</br>
第三天：ans=max(ans,dp[3]+maxm-prices[2])=6，maxm=max(maxm,prices[2])=7；</br>
第二天：ans=max(ans,dp[2]+maxm-prices[1])=6，maxm=max(maxm,prices[1])=7；</br>
第一天：ans=max(ans,dp[1]+maxm-prices[0])=6，maxm=max(maxm,prices[0])=7；</br>
最终结果为ans=6。
