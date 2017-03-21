class Solution {
public:
    using ll = long long;

    bool canSplit(vector<int>& nums, int m, ll limit) {
        ll now = 0;
        int c = 1, cnt = nums.size();
        for (int i = 0; i < cnt; i++) {
            now += nums[i];
            if (now > limit) {
                now = nums[i];
                ++c;
            }
        }
        return c <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        ll l = 0, r = 0;
        int cnt = nums.size();
        for (int i = 0; i < cnt; i++) {
            l = max(l, (ll)nums[i]);
            r += nums[i];
        }
        while (l < r) {
            ll mid = (l + r) >> 1LL;
            if (canSplit(nums, m, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};