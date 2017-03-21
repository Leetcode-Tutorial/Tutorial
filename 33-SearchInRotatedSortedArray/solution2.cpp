class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        //find the index of the smallest number
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[right]) left=mid+1;
            else right=mid;
        }
        int rot=left;
        left=0; right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int realmid=(mid+rot)%nums.size();
            if(nums[realmid]==target) return realmid;
            if(nums[realmid]<target) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
};
