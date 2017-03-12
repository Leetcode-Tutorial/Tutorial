class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int sz_x = matrix.size();
        if(!sz_x) return 0;// Deal with empty input.
        int sz_y = matrix[0].size();
        int ans(0);
        vector<vector<int>> len(sz_x, vector<int>(sz_y,0)); //Initialize Vector to record the maximum path from a point.
        for(int i=0; i<sz_x; i++)
            for(int j=0; j<sz_y; j++)
                if(len[i][j] == 0)
                    dfs(i, j, len, matrix, ans, sz_x, sz_y);
        return ans;
    }
    void dfs(const int x,const int y, vector<vector<int>>& len,const vector<vector<int>>& matrix, int &ans, const int &sz_x, const int &sz_y)
    {
        len[x][y] = 1;
        for(int i=0;i<4;i++)
        {
            int tmp_x = x+yd[i][0];
            int tmp_y = y+yd[i][1];
            if(tmp_x>=0 && tmp_x<sz_x && tmp_y>=0 && tmp_y<sz_y && matrix[tmp_x][tmp_y] > matrix[x][y])//Boundary Conditions Checking
            {
                if(!len[tmp_x][tmp_y]) dfs(tmp_x, tmp_y, len, matrix, ans, sz_x, sz_y);//If haven't visit (tmp_x, tmp_y), just do it.
                len[x][y] = max(len[tmp_x][tmp_y]+1, len[x][y]);
            }
        }
        ans = max(ans, len[x][y]);// Update answer.
    }
private:
    const int yd[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
};
