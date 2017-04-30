int findRotateSteps(string ring, string key)
{
    int lenr=ring.size(),lenk=key.size();
    int dp[lenk+1][lenr];
    memset(dp,0x7f,sizeof(dp));//将数组所有值初始化为无穷大
    dp[0][0]=0;//初始化边界
    for(int i=1;i<=lenk;i++)
    {
        for(int j=0;j<lenr;j++)
        {
            if(ring[j]!=key[i-1])continue;//此时不进行转移
            for(int k=0;k<lenr;k++)//状态转移，枚举上一次12点方向的所有字母以及此次转动是顺时针还是逆时针
            {
                dp[i][j]=min(dp[i][j],dp[i-1][k]+min((j-k+lenr)%lenr,(k-j+lenr)%lenr)+1);
            }
        }
    }
    int ans=1000000007;
    for(int i=0;i<lenr;i++)//求解答案
    {
        ans=min(ans,dp[lenk][i]);
    }
    return ans;
}
