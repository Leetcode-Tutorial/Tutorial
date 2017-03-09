class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        dfs(root,ans);
        return ans;
    }
    int dfs(TreeNode* cur, int& ans)
    {
        int x = (cur->left)? dfs(cur->left, ans):0;// 如果存在左儿子，则计算出左儿子的最大单链
        int y = (cur->right)? dfs(cur->right,  ans):0;//如果存在右儿子，则计算出右儿子的最大单链
        int z = x + y + cur->val;// 因为若一儿子的最大单链无法造成正贡献则直接取零，相当于不取该儿子的最大单链，所以题解中两种情况可合在一个式子来表示。计算出以当前结点为深度最小的路径的最大值
        ans = (z>ans)? z:ans;//更新全局的最大值
        x = x+cur->val;
        y = y+cur->val;
        if(x<y) x = y;//计算出当前节点的最大单链值
        return (x>0)? x:0;//返回最大单链的值，如果其为负数则无法对父节点造成正的贡献，不如不取，即直接返回0
    }
};
