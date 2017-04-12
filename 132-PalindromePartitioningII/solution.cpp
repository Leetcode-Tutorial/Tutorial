class Solution
{
public:
    int minCut(string s)
    {
        int n=s.size();

        bool isp[n][n];
        memset(isp,0,sizeof(isp));
        vector<int> mr(n);
        for(int i=0;i<n;i++)
            mr[i]=i;
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0&&r<n)
            {
                if(s[l]==s[r])     isp[l][r]=true,mr[l]=max(mr[l],r);
                else    break;
                l--,r++;
            }
            l=i,r=i+1;
            while(l>=0&&r<n)
            {
                if(s[l]==s[r])     isp[l][r]=true,mr[l]=max(mr[l],r);
                else    break;
                l--,r++;
            }
        }

        vector<int> dp(n,n);
        for(int i=0;i<n;i++)
        {
            if(isp[0][i])    dp[i]=0;
            for(int j=1;j<=i;j++)
                if(isp[j][i])
                    dp[i]=min(dp[i],dp[j-1]+1);
        }
        return dp[n-1];
    }
};
