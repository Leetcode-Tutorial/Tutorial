class Solution {
public:
    int numTrees(int n) {
        //首先考虑清楚初始条件
        if(n==1||n==0)
            return 1;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;                         //可以颠倒
        dp[0] = 1;

        for(int i = 3;i<=n;i++)            //对每一个dp[n]的
        {
            for(int j = 1;j<=i;j++)         //进行拆分
            {
                dp[i] += dp[i-j]*dp[j-1];
            }
        }
        return dp[n];
    }
};
