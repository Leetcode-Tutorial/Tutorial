class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[right]){ //二分中点在左侧有序序列中
                if(target < nums[mid] && target >= nums[left]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{ //二分中点在右侧有序序列中或者整体有序序列中
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid -1;
                }
            }
        }
        return !nums.empty() && nums[left] == target ? left : -1;
    }
};
