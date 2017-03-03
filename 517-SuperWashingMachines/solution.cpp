class Solution {
public:
    int cnt[10005];
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) 
            sum += machines[i];
        if (sum % n != 0) return -1;
        int avg = sum / n;
        for (int i = 0; i < n - 1; i++) {
            machines[i + 1] -= avg - machines[i]; 
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = avg - machines[i], y = avg - machines[i + 1];
            if (x > 0 && y < 0) {
                ans = max(ans, abs(x) + abs(y));
                ++i;
            }
            else ans = max(ans, abs(x));
        }
        return ans;
    }
};