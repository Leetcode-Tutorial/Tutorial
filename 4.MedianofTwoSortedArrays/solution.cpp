class Solution {
public:
    double getK(vector<int> nums1, vector<int> nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) {
            return getK(nums2, nums1, k);
        }
        // boundary
        if(m == 0) {
            return nums2[k - 1];
        } 
        if(k == 1) {
            return min(nums1[0], nums2[0]);
        }
        
        int a = min(k / 2, m), b = k - a;
        if(nums1[a - 1] < nums2[b - 1]) {
            if(nums1.begin() + a != nums1.end()) {
                vector<int>nums(nums1.begin() + a, nums1.end());
                return getK(nums, nums2, k - a);
            } else {
                vector<int>nums;
                return getK(nums, nums2, k - a);
            }
        } else if(nums1[a - 1] == nums2[b - 1]) {
            return nums1[a - 1];
        } else {
            if(nums2.begin() + b != nums2.end()) {
                vector<int>nums(nums2.begin() + b, nums2.end());
                return getK(nums1, nums, k - b);
            } else {
                vector<int>nums;
                return getK(nums1, nums, k - b);
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if((m + n) % 2 == 0) {
            return (getK(nums1, nums2, (m + n + 1) / 2) + getK(nums1, nums2, (m + n + 2) / 2)) / 2.0;
        } else {
            return getK(nums1, nums2, (m + n + 1) / 2) * 1.0;
        }
    }
};
