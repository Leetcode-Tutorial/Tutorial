class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='0') continue;
                if(i>0&&j>0) matrix[i][j]='1'+ min(matrix[i-1][j-1]-'0', min(matrix[i-1][j]-'0', matrix[i][j-1]-'0'));
                ret = ret >= (matrix[i][j]-'0') ? ret : (matrix[i][j]-'0');
            }
        }
        return ret*ret;
    }
};
