class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        // dp[i] represents the difference of the last two numbers of wiggle subsequence of nums[0...i]
        vector<int> dp(nums.size());
        dp[1] = nums[1]-nums[0];
        // dp[1]==0 is same as nums[1]==nums[0], so the length of wiggle subsequence of nums[0,1] is 1
        int res = dp[1] ? 2 : 1;
        for(int i=2; i<nums.size(); i++){
            int temp = nums[i]-nums[i-1];
            if(temp * dp[i-1] < 0 || (dp[i-1]==0&&temp!=0)) {
                // temp * dp[i-1] < 0 satisfies the conditions of  wiggle sequence
                // dp[i-1]==0 means that nums[0...i-1] contains same numbers
                dp[i] = temp;
                res += 1;
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return res;
    }
};
