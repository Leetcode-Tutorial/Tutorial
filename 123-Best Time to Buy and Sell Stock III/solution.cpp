int maxProfit(vector<int>& prices)
{
    int len=prices.size();
    if(len==0)return 0;
    int dp[len+1];
    dp[0]=0;//初始化边界
    int minm=1e9+7;//最小价格初始化为极大值
    for(int i=1;i<=len;i++)
    {
        dp[i]=max(dp[i-1],prices[i-1]-minm);//更新前i天交易一次的最大收益
        minm=min(minm,prices[i-1]);//更新最小价格
    }
    int maxm=-1,ans=dp[len];//初始化最终结果，最大价格初始化为极小值
    for(int i=len;i>0;i--)
    {
        ans=max(ans,dp[i]+maxm-prices[i-1]);//将最终结果与前i天的最大收益外加第i天后的最大收益比较并更新
        maxm=max(maxm,prices[i-1]);//更新最大价格
    }
    return ans;
}
