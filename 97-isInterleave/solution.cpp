class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool dp[1005][1005];
        int n = s1.length (), m = s2.length ();
        if (n+m != s3.length ()) return 0;
        if (n == 0 || m == 0) {
            return s1+s2 == s3;
        }
        for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[i][j] = 0;
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) if (dp[i][j]) {
                if (i < n && s1[i] == s3[i+j]) dp[i+1][j] = 1;
                if (j < m && s2[j] == s3[i+j]) dp[i][j+1] = 1;
            }
        }
        return dp[n][m];
    }
};
