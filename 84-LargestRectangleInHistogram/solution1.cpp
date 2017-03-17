class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //Time Limit Exceeded
        int ret = 0;
        for(int i=0; i<heights.size(); i++){
            int left_index = i-1;
            int right_index = i+1;
            while(left_index>=0 && heights[left_index]>=heights[i]) left_index--;
            while(right_index<heights.size() && heights[right_index]>=heights[i]) right_index++;
            ret = max(ret, heights[i]*(right_index - left_index - 1));
        }
        return ret;
    }
};
