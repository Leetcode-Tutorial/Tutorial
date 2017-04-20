class Solution {
public:
    void solve(vector<vector<char>>& board){
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O'){
                    bfs(board, i, j);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='E'){
                    board[i][j]='O';
                }
            }
        }
        return;
    }
private:
    void bfs(vector<vector<char>>& board, int row, int col){
        int m = board.size();
        int n = board[0].size();
        vector<pair<int, int>> container{make_pair(row, col)};
        queue<pair<int, int>> pos_queue;
        pos_queue.push(make_pair(row, col));
        board[row][col] = 'E';
        //是否可以扩展到边界的标记：如果可以扩展到边界 flag==true，否则，flag==false
        bool flag=false;
        while(!pos_queue.empty()){
            pair<int, int> temp = pos_queue.front();
            pos_queue.pop();
            container.emplace_back(temp);
            if(temp.first==0||temp.second==0||temp.first==m-1||temp.second==n-1) flag=true;
            for(const auto &direction: directions){
                pair<int, int> next(temp.first+direction.first, temp.second+direction.second);
                if(next.first>=0&&next.first<m&&next.second>=0&&next.second<n&&board[next.first][next.second]=='O'){
                    board[next.first][next.second] = 'E';
                    pos_queue.push(next);
                }
            }
        }
        //不能扩展到边界，说明这些 'O' 被 'X' 包围了，可以将它们都变为 'X'
        if(!flag){
            for(auto& pos: container){
                board[pos.first][pos.second]='X';
            }
        }
        return;
    }
    
    vector<pair<const int, const int>> directions{make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
    
};
