class Solution {
public:
    int calArea(int left, int right, vector<int>& height) {
        int realHeight = min(height[left], height[right]);
        int width = right - left;
        return width * realHeight;
    }
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size() - 1;
        int ans = calArea(left, right, height);
        
        while(left < right) {
            if(height[left] <= height[right]) {
                left ++;
            } else {
                right --;
            }
            ans = max(ans, calArea(left, right, height));
        }
        return ans;
    }
};
