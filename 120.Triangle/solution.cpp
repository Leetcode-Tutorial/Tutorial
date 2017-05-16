class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int lenr = triangle.size();
        vector<int>dp(lenr);
        
        if(lenr == 0) return 0;
        
        dp[0] = triangle[0][0];
        for(int i = 1; i < lenr; i ++) {
            for(int j = i; j >= 0; j --) {
                if(j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                } else if(j == i) {
                    dp[j] = dp[j - 1] + triangle[i][j];
                } else {
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
                }
            }
        }
        
        int ans = dp[0];
        for(int j = 1; j < lenr; j ++) {
            ans = min(ans, dp[j]);
        }
        return ans;
    }
};
