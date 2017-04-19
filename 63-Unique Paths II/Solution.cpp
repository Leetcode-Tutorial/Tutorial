class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> cnt(row, vector<int>(col, 0));
        if(obstacleGrid[0][0]) return 0;
        cnt[0][0] = 1;
        for(int i=1;i<col;i++)
            if(!obstacleGrid[0][i]) cnt[0][i] = cnt[0][i-1]; // 预处理第一行的方案数
        for(int i=1;i<row;i++)
            if(!obstacleGrid[i][0]) cnt[i][0] = cnt[i-1][0]; // 预处理第一列的方案数
        for(int i=1;i<row;i++)
            for(int j=1;j<col;j++)
            if(!obstacleGrid[i][j]) cnt[i][j] = cnt[i-1][j] + cnt[i][j-1]; // 通过递推计算出方案数目
        return cnt[row-1][col-1];
    }
};
