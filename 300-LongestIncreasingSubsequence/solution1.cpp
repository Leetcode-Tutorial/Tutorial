class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int res=0;//记录最大长度
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
            res=max(res, dp[i]);
        }
        return res;
    }
};
