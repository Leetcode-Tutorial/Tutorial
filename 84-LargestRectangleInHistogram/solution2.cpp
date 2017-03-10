class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //solution 2: 9ms (beats 93.96%)
        if(heights.size()==0) return 0;
        stack<int> index_stack;
        int ret = 0;
        for(int i=0; i<heights.size(); i++){
            while(!index_stack.empty() && heights[index_stack.top()] >= heights[i]){
                int index = index_stack.top();
                index_stack.pop();
                ret = max(ret, heights[index]*(i-(index_stack.empty()? 0 : index_stack.top()+1)));
            }
            index_stack.push(i);
        }
        
        while(!index_stack.empty()){
            int index = index_stack.top();
            index_stack.pop();
            int right = heights.size();
            int left = index_stack.empty()? 0 : index_stack.top()+1;
            ret = max(ret, heights[index]*(right-left));
        }
        return ret;
    }
};
