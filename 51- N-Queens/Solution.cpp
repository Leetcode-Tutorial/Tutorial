class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        col.resize(n, true);
        left_dia.resize(2*n, true);
        right_dia.resize(2*n, true);
        try_to_solve(ans, cur, 0, n);
        return ans;
    }
private:
    void try_to_solve(vector<vector<string>> &ans, vector<string> &cur, int row, int sz)
    {
        if(row == sz)
        {
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<sz;i++)
            if(col[i]&& left_dia[row+i]&& right_dia[row-i+sz])//检查当前前是否可放
            {
                col[i] = false;
                left_dia[row+i] = false;
                right_dia[row-i+sz] = false;
                cur[row][i] = 'Q';
                try_to_solve(ans, cur, row+1, sz);
                // 回溯
                col[i] = true;
                left_dia[row+i] = true;
                right_dia[row-i+sz] = true;
                cur[row][i] = '.';
            }
    }
    vector<bool> col;////用于当前列上的点是否可用
    vector<bool> left_dia;//用于标记与次对角线平行的一条直线上的点是否可用
    vector<bool> right_dia;//用于标记与主对角线平行的一条直线上的点是否可用
};
