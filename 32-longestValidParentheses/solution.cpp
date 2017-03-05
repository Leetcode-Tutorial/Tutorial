class Solution {
public:
    int sum[50005], dp[50005][18], n;
    void rmq_init () {
        for (int i = 0; i < n; i++) dp[i][0] = sum[i];
        for (int j = 1; (1<<j) <= n; j++) {
            for (int i = 0; i+(1<<j)-1 < n; i++) {
                dp[i][j] = min (dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
            }
        }
    }
    int rmq (int l, int r) {
        int k = 0;
        while ((1<<(k+1)) <= r-l+1) k++;
        return min (dp[l][k], dp[r-(1<<k)+1][k]);
    }
    int longestValidParentheses(string s) {
        n = s.length ();
        map <int, int> mp; mp.clear ();
        
        for (int i = 0; i < n; i++) {
            sum[i] = (i ? sum[i-1] : 0) + (s[i] == '(' ? 1 : -1);
        }
        for (int i = n-1; i >= 0; i--) if (!mp.count (sum[i])) {
            mp[sum[i]] = i;
        }
        if (!mp.count (0)) mp[0] = -1;
        rmq_init ();
        
        int ans = 0;
        for (int i = 0; i < n-1; i++) if (s[i] == '(') {
            int pre = (i ? sum[i-1] : 0), next;
            int l = i+1, r = n-1;
            while (r-l > 1) {
                int mid = (l+r)>>1;
                if (rmq (i, mid) >= pre) l = mid;
                else r = mid;
            }
            if (sum[l] == pre) ans = max (ans, l-i+1);
            else if (sum[r] == pre) ans = max (ans, r-i+1);
            else ans = max (ans, mp[pre]-i+1);
        }
        return ans;
    }
};
