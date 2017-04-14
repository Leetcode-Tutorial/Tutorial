class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        vector<int> res(n, 1);        
        for(int i = 0; i < n; i++) {
            res[i] *= l;
            l *= nums[i];
        }
        int r = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= r;
            r *= nums[i];
        }
        return res;
    }
};