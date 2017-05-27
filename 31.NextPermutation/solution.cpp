class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0;
        int j;
        for(j = nums.size() - 1; j > 0; j --) {
            if(nums[j - 1] < nums[j]) {
                i = j;
                break;
            }
        }
        if(j == 0) {
            sort(nums.begin(), nums.end());
        } else {
            for(int k = nums.size() - 1; k >= 0; k --) {
                if(nums[i - 1] < nums[k]) {
                    j = k;
                    break;
                }
            }
            swap(nums[i - 1], nums[j]);
            j = nums.size() - 1;
            while(i < j) {
                swap(nums[i], nums[j]);
                i ++;
                j --;
            }
        }
    }
};
