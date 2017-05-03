class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cal(m, vector<int>(n, 1));//所有单元的方案数预置为1，免去了单独初始化第一行和第一列的麻烦
        cal[0][0]=1;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                cal[i][j] = cal[i-1][j] + cal[i][j-1] ;
        return cal[m-1][n-1];
    }
};
