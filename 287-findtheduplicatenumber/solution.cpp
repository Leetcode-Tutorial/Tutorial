class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;
        while (l < r) {
            int m = (l + r) >> 1, cnt = 0;
            for (int i = 0; i < n; i++) 
                if (nums[i] <= m) cnt++;
            if (cnt > m) r = m;
            else l = m + 1;
        }
        return l;
    }
};