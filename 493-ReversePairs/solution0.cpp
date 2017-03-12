class Solution {
public:
    int mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return 0;
        int m = (l+r) >> 1;
        int ans = mergeSort(nums, l, m) + mergeSort(nums, m+1, r);
        for(int i = l, j = m+1; i <= m; i++){
            while(j <= r && nums[i] > nums[j]*2LL) j++;
            ans += j-1-m;
        }
        sort(nums.begin()+l, nums.begin()+r+1);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
