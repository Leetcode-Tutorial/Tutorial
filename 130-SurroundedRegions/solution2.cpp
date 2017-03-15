class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        for(int i=0; i<n; i++){
            if(board[0][i]=='O') bfs(board, 0, i);
            if(board[m-1][i]=='O') bfs(board, m-1, i);
        }
        for(int i=0; i<m; i++){
            if(board[i][0]=='O') bfs(board, i, 0);
            if(board[i][n-1]=='O') bfs(board, i, n-1);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j] = board[i][j]=='E' ? 'O':'X';
            }
        }
    }
private:
    void bfs(vector<vector<char>>& board, int row, int col){
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> pos_queue;
        pos_queue.push(make_pair(row, col));
        board[row][col] = 'E';
        while(!pos_queue.empty()){
            pair<int, int> temp = pos_queue.front();
            pos_queue.pop();
            for(const auto &direction: directions){
                pair<int, int> next(temp.first+direction.first, temp.second+direction.second);
                if(next.first>=0&&next.first<m&&next.second>=0&&next.second<n&&board[next.first][next.second]=='O'){
                    //you would better change current character from 'O' to 'E' immediately
                    board[next.first][next.second] = 'E';
                    pos_queue.push(next);
                }
            }
        }
        return;
    }
    
    vector<pair<const int, const int>> directions{make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
};
