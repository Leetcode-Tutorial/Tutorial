class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        vector<int> dp(11);
        dp[0] = 1;
        
        for(int i = 1; i <= 10; i ++) {
            int temp = 9;
            for(int j = 9; j > 10 - i; j--) {
                temp *= j;
            }
            dp[i] = temp + dp[i - 1];
        }
        
        if(n > 10) return dp[10];
        else return dp[n];
    }
};
