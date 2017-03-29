class Solution {
public:
    bool res = false;
    //int visited[board.size()][board[0].size()];
    int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};        //上下左右4个方向
    void serach_board(int i,int j,int level,string word,vector<vector<char>>& board,vector<vector<int>>& visited)
    {
        if(res)
            return;
        if(level==word.length())         //先进来再说
            res = true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size())
            return;
        if(visited[i][j])                //这些都相当于剪枝了，但是最坏的情况还是很坏
            return;
        visited[i][j]=1;                 //进来才处理这个东西
        if(board[i][j]==word[level])     //如果满足它，就可以继续搜索下去
        {
            for(int k = 0;k<4;k++)
            {
                int new_i = i+direction[k][0];
                int new_j = j+direction[k][1];
               /* if(new_i>=0&&new_i<board.size()&&new_j>=0&&new_j<board[0].size())
                {
                    //满足边界条件的话
                    //如果这下面没有return的话，那么得到的结果是返回不了的
                    serach_board(new_i,new_j,level+1,word,board,visited); 
                }
                */
                serach_board(new_i,new_j,level+1,word,board,visited); 
            }
        }
        visited[i][j]=0;                           //一定要保证的是使他变回来
        //return false;              
    }
    bool exist(vector<vector<char>>& board, string word) {
        // 此题用搜索
        //二维矩阵的每个点都可以作为搜索的开始
        int row = board.size(),col = board[0].size();
        int i,j;
        vector<vector <int> > visited(row ,vector<int>(col,0));
       
        for(i = 0;i<row;i++)
        {
            for(j = 0;j<col;j++)
            {
                serach_board(i,j,0,word,board,visited);
                    if(res)
                    return true;
            }
        }
        return false;            //如果前面都么有返回true，那么就返回false
    };
};