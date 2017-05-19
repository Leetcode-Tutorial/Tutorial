class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N==0) return 0;
        int dp[m][n][N+1];
        memset(dp, 0, sizeof(dp));
        for (int l=1; l<=N; l++)
            for (int row=0; row<m; row++)
                for (int col=0; col<n; col++){
                    dp[row][col][l] += (row==0?1:dp[row-1][col][l-1]);
                    dp[row][col][l] += (row==m-1?1:dp[row+1][col][l-1]);dp[row][col][l]%=int(1e9+7);
                    dp[row][col][l] += (col==0?1:dp[row][col-1][l-1]);dp[row][col][l]%=int(1e9+7);
                    dp[row][col][l] += (col==n-1?1:dp[row][col+1][l-1]);dp[row][col][l]%=int(1e9+7);
                }
        return dp[i][j][N];
    }
};
