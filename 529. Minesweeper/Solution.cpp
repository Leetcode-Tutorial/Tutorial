class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> ans = board;
        int x = click[0], y = click[1];
        //当挖到的块时特判，仅改变自身
        if(ans[x][y] == 'M')
        {
            ans[x][y] = 'X';
            return ans;
        }
        dig_out(x, y, ans);
        return ans;
    }
    void dig_out(int x, int y, vector<vector<char>> &ans)
    {
        queue<pair<int,int>> Q;
        vector<vector<bool>> visited(ans.size(), vector<bool>(ans[0].size(), false));
        Q.push(make_pair(x,y));
        visited[x][y] = true;
        while(!Q.empty())
        {
            int cnt = 0;
            x = Q.front().first; y = Q.front().second;
            Q.pop();
            //预先统计出当前这块的八个方向是否存在地雷
            for(int i=0; i<8; i++)
            {
                int tmpx = x + MV[i][0];
                int tmpy = y + MV[i][1];
                if(tmpx<0||tmpx>=ans.size()||tmpy<0||tmpy>=ans[0].size()) continue;
                if(ans[tmpx][tmpy]=='M') cnt++;
            }
            //如果存在至少一枚雷则显示周围雷数
            if(cnt) ans[x][y] = '0'+cnt;
            //不存在类则拓展周围格子
            else
            {
                ans[x][y] = 'B';
                for(int i=0; i<8; i++)
                {
                    int tmpx = x + MV[i][0];
                    int tmpy = y + MV[i][1];
                    if(tmpx<0||tmpx>=ans.size()||tmpy<0||tmpy>=ans[0].size()) continue;
                    if(ans[tmpx][tmpy]=='E'&& !visited[tmpx][tmpy])
                    {
                        visited[tmpx][tmpy] = true;
                        Q.push(make_pair(tmpx,tmpy));
                    }
                }
            }
        }
    }
private:
    const int MV[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};//定义格子拓展的八个方向
};
