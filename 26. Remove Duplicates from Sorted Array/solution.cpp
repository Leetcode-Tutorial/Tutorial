class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        if(nums.size() <= 1)
            return nums.size();
        for(int r = 1; r < nums.size(); r++){
            if(nums[l] != nums[r])
                nums[++l] = nums[r];
        }
        return l+1;
    }
};