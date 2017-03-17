class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) {
            return 0;
        } else if(len == 1) {
            return nums[0];
        } else if(len == 2) {
            return max(nums[0], nums[1]);
        } else {
            vector<int> dp;
            dp.push_back(nums[0]);
            dp.push_back(max(dp[0], nums[1]));
            for(int i = 2; i < len; i ++) {
                dp.push_back(max(dp[i - 2] + nums[i], dp[i - 1]));
            }
            return dp[len - 1];
        }
        return 0;
    }
};
