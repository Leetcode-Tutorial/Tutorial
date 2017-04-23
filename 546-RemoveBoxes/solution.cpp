class Solution
{
    int dp[105][105][105];
    int dfs(int l,int r,int k,vector<int> &b)
    {
        if(l>r)    return 0;
        int &d=dp[l][r][k];
        if(d!=-1)    return d;
        d=dfs(l,r-1,0,b)+(1+k)*(1+k);
        for(int i=l;i<r;i++)
            if(b[i]==b[r])
                d=max(d,dfs(l,i,1+k,b)+dfs(i+1,r-1,0,b));
        return d;
    }
public:
    int removeBoxes(vector<int>& boxes)
    {
        memset(dp,-1,sizeof(dp));
        return dfs(0,boxes.size()-1,0,boxes);
    }
};
