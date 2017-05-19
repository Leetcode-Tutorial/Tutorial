class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int dp[nums.size()][nums.size()];
        for (int l=1; l<=nums.size(); l++)
            for (int i=0; i+l-1<nums.size(); i++){
                int j = i+l-1;
                if(i==j) dp[i][j] = nums[i];
                else dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        return dp[0][nums.size()-1] >= 0;
    }
};
