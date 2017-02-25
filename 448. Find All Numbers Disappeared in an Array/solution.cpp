class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int tmp = nums[i]-1;
            if(tmp > 0){
                
                if(nums[tmp] > 0){
                    nums[tmp] = -nums[tmp];
                }
            }else{
                tmp = -tmp;
                if(nums[tmp] > 0){
                    nums[tmp] = -nums[tmp];
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < len; i++){
            int tmp = nums[i];
            if(tmp > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
