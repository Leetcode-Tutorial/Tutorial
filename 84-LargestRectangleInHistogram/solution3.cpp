class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // solution 3: push a sentinel node back into the end of heights to make the code logic more concise.
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
