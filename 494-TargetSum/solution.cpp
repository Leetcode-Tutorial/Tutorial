class Solution {
public:
    int dp[1005];

    int findTargetSumWays(vector<int>& nums, int s) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum < s || (s + sum) % 2) return 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = (s + sum) / 2; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        } 
        return dp[(s + sum) / 2]; 
    }   
};