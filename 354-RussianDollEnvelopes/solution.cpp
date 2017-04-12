class Solution
{
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes)
    {
        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        if(n==0)    return 0;
        int dp[n];
        for(int i=0;i<n;i++)    dp[i]=1;
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(envelopes[i].first>envelopes[j].first
                        &&envelopes[i].second>envelopes[j].second)
                    dp[i]=max(dp[i],dp[j]+1);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
        return ans;
    }
};
