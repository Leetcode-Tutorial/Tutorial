class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        vector<int> heights(matrix[0].size(), 0);
        vector<int> lefts(matrix[0].size(), 0);
        vector<int> rights(matrix[0].size(), matrix[0].size());
        int ret = 0;
        for(auto& row: matrix){
            int cur_left=0;
            int cur_right=row.size();
            for(int i=0; i<row.size(); i++){
                if(row[i]=='0'){
                    heights[i]=0;
                    lefts[i]=0;
                    cur_left=i+1;
                }
                else{
                    heights[i]+=1;
                    lefts[i] = max(lefts[i], cur_left);
                }
            }
            for(int i=row.size()-1; i>=0; i--){
                if(row[i]=='0'){
                    rights[i]=row.size();
                    cur_right=i;
                }
                else rights[i] = min(rights[i], cur_right);
            }
            for(int i=0; i<row.size(); i++){
                ret = max(ret, heights[i]*(rights[i]-lefts[i]));
            }
        }
        return ret;
    }
};
