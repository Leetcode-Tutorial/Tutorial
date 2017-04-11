class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //如果有一个元素为0，那么将这一行，这一列都置为0
        //我这采取的办法是碰到一个为0了，那么我就将这一行的行首以及列首置为0
        int row = matrix.size();
        if(row==0)
            return;
        bool flag = false,flag_row = false,flag_col = false;            
        int col  = matrix[0].size();
        if(matrix[0][0] == 0)           //看一开始matrix[0][0]是否为0
            flag = true;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i==0)
                        flag_row = true;    //如果此时是第一行有0的话，记录是第一行，后面matrix[0][0]=0,我就知道应该还原哪些了
                    if(j==0)
                        flag_col = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1;i<row;i++)          //如果这行行首有为0，那么将这一行全部置为0
        {
            if(matrix[i][0]==0)
            {
                for(int j = 0;j<col;j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i  =1;i<col;i++)
        {
            if(matrix[0][i] == 0)
            {
                for(int j  =0;j<row;j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
       if(matrix[0][0]==0)
       {
           if(flag_row)                    //判断是行使得[0][0]点为0的，还是列使得，处理不同
           {
            for(int i = 0;i<col;i++)
            {
                matrix[0][i] = 0;
            }
           }
           if(flag_col)
        {
            for(int i = 0;i<row;i++)
            {
                matrix[i][0] = 0;
            }
         }
       }  
    }
};