class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int>dp(num + 1, 0);
        dp[0] = 0;
        if(num == 0) return dp;
        dp[1] = 1;
        if(num == 1) return dp;
        
        int j = 2;
        int size = 2;
        while(j <= num) {
            for(int i = 0;i < size && j <= num; i ++, j ++) {
                dp[j] = dp[i] + 1;
            }
            size = j;
        }
        return dp;
    }
};
