class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans(0, vector<int>(0,0));
        vector<int> cur(0,0);
        dfs(-1, ans, cur, nums);
        return ans;
    }
    void dfs(int no, vector<vector<int>> &ans, vector<int> &cur, vector<int>& nums)
    {
        //使用M记录每个与当前串组合过的数字
        unordered_map<int,bool> M;
        int x = (no<0)? -111:nums[no];
        for(int i=no+1;i<nums.size();i++)
            //确定当前尚未与值为nums[i]的数字组合过
        if(nums[i]>=x&&M.find(nums[i]) == M.end())
        {
            M[nums[i]] = true;
            cur.push_back(nums[i]);
            //如果当前序列的长度大于等于2则加入到答案之中
            if(cur.size()>=2) ans.push_back(cur);
            dfs(i,ans,cur,nums);
            //回溯
            cur.pop_back();
        }
    }
};
