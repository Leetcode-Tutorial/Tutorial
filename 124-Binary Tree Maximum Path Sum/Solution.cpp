class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        dfs(root,ans);
        return ans;
    }
    int dfs(TreeNode* cur, int& ans)
    {
        int x = (cur->left)? dfs(cur->left, ans):0;// visit left_son
        int y = (cur->right)? dfs(cur->right,  ans):0;// visit right_son
        int z = x + y + cur->val;
        ans = (z>ans)? z:ans;
        x = x+cur->val;
        y = y+cur->val;
        if(x<y) x = y;
        return (x>0)? x:0;
    }
};
