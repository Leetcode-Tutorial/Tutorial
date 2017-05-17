class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> ans;
        int n = matrix.size();
        if(n==0)
            return ans;
        int m = matrix[0].size();
        vector<vector<int>> Cl(n, vector<int>(m, 0));
        bfs(n,m,1,matrix,Cl);//标记Pacific所能到达的单元格
        bfs(n,m,2,matrix,Cl);//标记Atlantic所能到达的单元格

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(Cl[i][j]==3) ans.push_back(make_pair(i,j));//检查是否两个海洋都能够到达
        return ans;
    }
private:
    void bfs(int n, int m, int cl, vector<vector<int>>& matrix, vector<vector<int>> &Cl)
    {
        queue<pair<int,int>> Q;
        Init_Q(n,m,cl,Q,Cl);//初始化一开始的种子单元格
        while(!Q.empty())
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for(int i=0;i<4;i++)
            {
                int tmpx = x + mv[i][0];
                int tmpy = y + mv[i][1];
                if(tmpx<0||tmpx>=n||tmpy<0||tmpy>=m) continue;//检查边界
                if(matrix[tmpx][tmpy]>=matrix[x][y]&&(Cl[tmpx][tmpy]&cl)==0)//高度要保证不下降，同时防止重复遍历
                {
                     Cl[tmpx][tmpy] |= cl;
                     Q.push(make_pair(tmpx,tmpy));
                }
            }
        }
    }
    void Init_Q(int n, int m, int cl, queue<pair<int,int>>& Q, vector<vector<int>> &Cl)
    {
        if(cl == 1)//如果是Pacific则把上方和左方的单元格先加入至队列
        {
            for(int i=0;i<m;i++)
            {
                Q.push(make_pair(0,i));
                Cl[0][i] |= cl;
            }
            for(int i=1; i<n; i++)
            {
                Q.push(make_pair(i, 0));
                Cl[i][0] |= cl;
            }
        }
        else//如果是Atlantic则把下方和右方的单元格加入到初始队列之中
        {
            for(int i=0;i<m;i++)
            {
                Q.push(make_pair(n-1,i));
                Cl[n-1][i] |= cl;
            }
            for(int i=n-1; i>=0; i--)
            {
                Q.push(make_pair(i, m-1));
                Cl[i][m-1] |= cl;
            }
        }
    }
    const int mv[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};//建立上下左右四个方向的移动
};
