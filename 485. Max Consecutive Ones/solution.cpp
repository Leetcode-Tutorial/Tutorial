class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int tmp = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int old = tmp;
            tmp += nums[i];
            ans = max(ans, tmp);
            if(tmp == old){
                tmp = 0;
            }
        }
        return ans;
    }
};
