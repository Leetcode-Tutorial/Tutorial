class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int i,j;
        int maxx = 1<<len;
        vector<vector<int>> res;
        for(i = 0;i<maxx;i++)
        {
            vector<int>temp;
            j = i;                   //在想象的时候，就把它想成32位数字来考虑
            int count  = 0;          //控制我这个时候是第几位了
            while(j>0)
            {
                if(j&1)
                {
                    temp.push_back(nums[count]);
                }
                count++;
                j = j>>1;
            }
            res.push_back(temp);
        }
        return res;
    }
};