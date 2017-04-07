class Solution {
    public:
    int longestPalindromeSubseq(string s) {
        int dp[1000][1000];
        memset(dp,0,sizeof(dp));
        for(int i=s.size()-1; i>=0; i--){
            dp[i][i]=1;
            for(int j=i+1; j<s.size(); j++){
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][s.size()-1];
    }
};
