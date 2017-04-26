class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int col(matrix[0].size());//存储矩阵列数
        const int row(matrix.size());//存储矩阵行数
        dis.resize(row, vector<int>(col, row+col));
        visited.resize(row, vector<bool>(col, false));
        for(int i=0;i<row;i++)
            for(int j=0; j<col; j++)
                if(matrix[i][j]==0)//将矩阵中为0的数字加入到队列中，并标记
                {
                    Q.push(make_pair(i,j));
                    dis[i][j]=0;
                    visited[i][j]=true;
                }
        bfs(row, col, matrix);
        return dis;
    }
private:
    bool boundary_check(int x,int y, const int &row, const int &col)//边界检查，检查当前点的坐标是否在矩阵范围之内
    {
        return (x>=0&&x<row) && (y>=0&&y<col);
    }
    void bfs(const int &row, const int &col,vector<vector<int>>& matrix)
    {
        while(!Q.empty())
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for(int i=0;i<4;i++)
            {
                int tmpx = x + mv[i][0];
                int tmpy = y + mv[i][1];
                if(!boundary_check(tmpx, tmpy, row, col) || visited[tmpx][tmpy]) continue;
                dis[tmpx][tmpy] = dis[x][y] + 1;
                Q.push(make_pair(tmpx, tmpy));
                visited[tmpx][tmpy] = true;
            }
        }
    }
    const int mv[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<int>> dis;
    vector<vector<bool>> visited;//标记一个结点是否已经加入过队列
    queue<pair<int, int>> Q;//存储待拓展的结点的队列
};
