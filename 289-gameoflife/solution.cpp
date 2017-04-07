class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {   // 枚举每一个方格中的细胞
                int cnt = 0;    // 周围细胞的存活数
                for (int p = max(i - 1, 0); p < min(i + 2, m); ++p)     // 枚举时考虑不超过边界
                    for (int q = max(j - 1, 0); q < min(j + 2, n); ++q)   // 枚举相邻的周围8个细胞以及自己一共9个细胞
                        cnt += board[p][q] & 1;
                if (cnt == 3 || cnt - board[i][j] == 3)  // cnt == 3说明有2~3个存活，cnt - board[i][j] == 3说明周围8个细胞中有正好3个存活
                    board[i][j] |= 2;      // 这两种情况下该细胞下一轮一定会存活，所以将其二进制第一位设置成1
            }
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1;
    }
};
