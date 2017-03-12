class Solution
{
public:
    int maxCoins(vector<int>& nums)
    {
        int n=nums.size();
        int arr[n+2],dp[n+2][n+2];
        arr[0]=arr[n+1]=1;
        for(int i=1;i<=n;i++)
            arr[i]=nums[i-1];
        for(int l=2;l<=n+2;l++)
            for(int i=0;i+l-1<n+2;i++)
            {
                int j=i+l-1;
                dp[i][j]=0;
                for(int k=i+1;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
            }
        return dp[0][n+1];
    }
};
