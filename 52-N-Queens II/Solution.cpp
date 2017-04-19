class Solution {
public:
     int totalNQueens(int n) {
        int cnt = 0;
        col.resize(n, true);
        left_dia.resize(2*n, true);
        right_dia.resize(2*n, true);
        try_to_solve(0, n, cnt);
        return cnt;
    }
private:
    void try_to_solve(int row, int sz, int &cnt)
    {
        if(row == sz)
        {
            cnt++;
            return;
        }
        for(int i=0;i<sz;i++)
            if(col[i]&& left_dia[row+i]&& right_dia[row-i+sz])//检查当前前是否可放
            {
                col[i] = false;
                left_dia[row+i] = false;
                right_dia[row-i+sz] = false;
                try_to_solve(row+1, sz, cnt);
                // 回溯
                col[i] = true;
                left_dia[row+i] = true;
                right_dia[row-i+sz] = true;
            }
    }
    vector<bool> col;////用于当前列上的点是否可用
    vector<bool> left_dia;//用于标记与次对角线平行的一条直线上的点是否可用
    vector<bool> right_dia;//用于标记与主对角线平行的一条直线上的点是否可用
};
