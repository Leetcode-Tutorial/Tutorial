class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        int pre1 = 0, Max1 = 0;
        for(int i = 0; i < nums.size() - 1; ++ i)  {
            int temp = pre1;
            pre1 = Max1;
            Max1 = max(temp + nums[i], pre1);
        }
        
        int pre2 = 0, Max2 = 0;
        for(int i = 1; i < nums.size(); ++ i) {
            int temp = pre2;
            pre2 = Max2;
            Max2 = max(temp + nums[i], pre2);
        }
        
        return max(Max1, Max2);
    }
};