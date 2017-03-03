class Solution {
public:
    bool dp[1110][1110];
    bool canCross(vector<int>& stones)
    {
        int n=stones.size();
        dp[0][0]=true;
        for(int i=1;i<n;i++)
            for(int j=1;j<n;j++)
            {
                int idx=stoneIdx(stones,stones[i]-j);
                if(idx==-1)
                {
                    dp[i][j]=false;
                    continue;
                }
                dp[i][j]=dp[idx][j];
                dp[i][j]=dp[i][j]||dp[idx][j-1];
                dp[i][j]=dp[i][j]||dp[idx][j+1];
            }
        for(int j=0;j<n;j++)
            if(dp[n-1][j])
                return true;
        return false;
    }
    int stoneIdx(vector<int> &stones, int pos)
    {
        int idx=lower_bound(stones.begin(),stones.end(),pos)-stones.begin();
        if(stones[idx]!=pos)    return -1;
        return idx;
    }
};
