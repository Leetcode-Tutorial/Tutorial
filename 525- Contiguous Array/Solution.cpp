class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int x = 0;//记录01平衡偏移量
        M[0] = -1;
        int ld = nums.size();
        for(int i = 0; i<ld; i++)
        {
            int y = nums[i];//更新偏移量
            if(y == 1) x++;
            else x--;
            if(M.find(x) != M.end())//如果HashTable当中不存在偏移量为x的记录
            {
                ans = max(ans, i-M[x]);
            }
            else
            {
                M[x] = i;
            }
        }
        return ans;
    }
private:
    unordered_map<int, int> M;
};
