class Solution {
public:
    int n, m, dp[1005][1005]; //来(i,j)位置至少需要多少hp
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size (), m = dungeon[0].size ();
        for (int i = 0; i < 1005; i++) for (int j = 0; j < 1005; j++) dp[i][j] = 1e9;
        dp[n-1][m-1] = (dungeon[n-1][m-1] <= 0 ? -dungeon[n-1][m-1]+1 : 1);
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (i-1 >= 0) {
                    dp[i-1][j] = min (dp[i-1][j], max (1, dp[i][j]-dungeon[i-1][j]));
                }
                if (j-1 >= 0) {
                    dp[i][j-1] = min (dp[i][j-1], max (1, dp[i][j]-dungeon[i][j-1]));
                }
            }
        }
        return dp[0][0];
    }
};
