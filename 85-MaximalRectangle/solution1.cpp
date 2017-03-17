class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // solution 1: based on Largest Rectangle in Histogram
        if(matrix.empty()) return 0;
        vector<int> heights(matrix[0].size());
        int ret = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                heights[j] = matrix[i][j]=='0' ? 0 : heights[j]+1;
            }
            ret = max(largestRectangleArea(heights), ret);
            heights.pop_back();
        }
        return ret;
    }
private:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        heights.emplace_back(0);
        stack<int> index_stack;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!index_stack.empty() && heights[index_stack.top()] >= heights[i])
            {
                int index = index_stack.top();
                index_stack.pop();
                ret = max(ret, heights[index]*(i-(index_stack.empty() ? 0 : index_stack.top()+1)));
            }
            index_stack.push(i);
        }
        return ret;
    }
};
