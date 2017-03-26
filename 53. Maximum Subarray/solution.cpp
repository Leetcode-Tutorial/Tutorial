class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int sum = 0, ans = nums[0], minsum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ans = max(ans, sum-minsum);
            minsum = min(minsum, sum);
        }
        return ans;
    }
};