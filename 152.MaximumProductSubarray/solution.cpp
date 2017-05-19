class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int len = nums.size();
        vector<int>dpmax(len);
        vector<int>dpmin(len);
        dpmax[0] = dpmin[0] = nums[0];
        
        int ans = nums[0];
        for(int i = 1; i < len; i ++) {
            dpmax[i] = max(nums[i], max(dpmax[i - 1] * nums[i], dpmin[i - 1] * nums[i]));
            dpmin[i] = min(nums[i], min(dpmax[i - 1] * nums[i], dpmin[i - 1] * nums[i]));
            ans = max(ans, dpmax[i]);
        }
       
        return ans;
    }                                                                                        
};
