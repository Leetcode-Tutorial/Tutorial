bool isMatch(string s, string p)
{
    int lens=s.length(),lenp=p.length();
    bool dp[lens+1][lenp+1];
    bool hastrue[lenp+1];
    memset(hastrue,false,sizeof(hastrue));
    dp[0][0]=true;
    hastrue[0]=true;
    for(int i=1;i<=lens;i++)
    {
        if(s[i-1]=='*')dp[i][0]=dp[i-1][0];//初始化边界
        else dp[i][0]=false;
    }
    for(int i=1;i<=lenp;i++)
    {
        if(p[i-1]=='*')dp[0][i]=dp[0][i-1];//初始化边界
        else dp[0][i]=false;
        if(dp[0][i])hastrue[i]=true;//更新hastrue
    }
    for(int i=1;i<=lens;i++)
    {
        if(s[i-1]=='*')//s[i-1]为*的时候
        {
            bool yes=false;
            for(int j=0;j<=lenp;j++)
            {
                if(dp[i-1][j]==true)yes=true;//找到第一个true就把变量置为true
                dp[i][j]=yes;//从第一个true开始一定为true
            }
        }
        else
        {
            for(int j=1;j<=lenp;j++)
            {
                if(p[j-1]=='*')//p[j-1]为true的时候
                {
                    dp[i][j]=hastrue[j-1];//与上一列是否有true的情况相同
                    if(dp[i][j])hastrue[j]=true;//更新hastrue
                }
                else if(s[i-1]=='?'||p[j-1]=='?'||s[i-1]==p[j-1])//单个字符匹配
                {
                    dp[i][j]=dp[i-1][j-1];
                    if(dp[i][j])hastrue[j]=true;//更新hastrue
                }
                else dp[i][j]=false;//单个字符不匹配
            }
        }
    }
    return dp[lens][lenp];
}
