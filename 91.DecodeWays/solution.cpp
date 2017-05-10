class Solution {
public:
    int numDecodings(string s) {
        
        int len = s.length();
        if(len == 0 || s[0] == '0') return 0;
        
        vector<int>dp(len + 1);
        dp[0] = 1;dp[1] = 1;
        
        for(int i = 2; i <= len; i ++ ){
            int value = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if(value % 10 == 0) {
                int temp = value / 10;
                if(temp == 1 || temp == 2) {
                    dp[i] = dp[i - 2];
                } else {
                    return 0;
                }
            } else {
                if(value < 10 || value > 26) {
                    dp[i] = dp[i - 1];
                } else {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
            }
        }
        return dp[len];
    }
};
