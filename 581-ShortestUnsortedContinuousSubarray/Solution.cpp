class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int i, j, l, r;
        for(i = 1; i < nums.size(); i++)
            if(nums[i] < nums[i-1]) break;
        if(i == nums.size()) return 0;// if already sorted

        int tmp = nums[i--];
        for(j = i+1; j < nums.size(); j++)
            if(nums[j] < tmp) tmp = nums[j];//tmp is min in [i+1, nums.size()]
        while(i >= 0&&nums[i] > tmp) i--;
        l = i+1;

        for(i = nums.size()-2; i >= l; i--)
            if(nums[i] > nums[i+1]) break;
        tmp = nums[i++];
        for(j = i-1; j >= l; j--)
            if(nums[j] > tmp) tmp = nums[j];//tmp is max in [l, i-1]
        while(i < nums.size()&&nums[i] < tmp) i++;
        r = i-1;
        return r-l+1;
    }
};
