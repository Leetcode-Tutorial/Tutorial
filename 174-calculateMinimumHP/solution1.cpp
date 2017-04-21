class Solution {
public:
    int n, m, dp[1005][1005];
    queue <pair <int, int> > q;
    bool check (long long x, vector<vector<int>>& a) {
        memset (dp, -1, sizeof dp); //i行j列的元素在中间结果都是正数情况下的最大和
        dp[0][0] = x+a[0][0];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i-1 >= 0 && dp[i-1][j] > 0 && dp[i-1][j]+a[i][j] > dp[i][j]) {
                    dp[i][j] = dp[i-1][j]+a[i][j];
                }
                if (j-1 >= 0 && dp[i][j-1] > 0 && dp[i][j-1]+a[i][j] > dp[i][j]) {
                    dp[i][j] = dp[i][j-1]+a[i][j];
                }
            }
        }
        return dp[n-1][m-1] > 0;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size (), m = dungeon[0].size ();
        long long l = 1, r = 1e9;
        while (r-l > 1) {
            long long mid = (l+r)/2;
            if (check (mid, dungeon)) r = mid;
            else l = mid;
        }
        if (check (l, dungeon)) return l;
        else return r;
    }
};
