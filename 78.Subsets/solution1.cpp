
class Solution {
public:
    void solve_subset(int level,vector<int>temp,vector<vector<int>>& res,vector<int>& nums)
    {
        if(level==nums.size())                              //到根结点就统计结果
        {
            res.push_back(temp);
            return;
        }
        solve_subset(level+1,temp,res,nums);                //这相当于左子树，从下一层回溯到这一层的时候，相当于出来一层了
        temp.push_back(nums[level]);                        //这里是在记录结果，依次往上递增，temp是临时变量，相当于起了一个分支，二叉树过程
        solve_subset(level+1,temp,res,nums);                //上一句和这一句加起来相当于右子树
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //这就是返回所有的子集,用搜索试试
        //搜索是一定可以构造搜索树的
        vector<vector<int>> res;
        vector<int>temp;
        solve_subset(0,temp,res,nums);
        return res;
    }
};
