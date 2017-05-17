/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs (TreeNode *u, int sum) { //判断从u出发能够找到长度是sum的路径
        sum -= u->val;
        if (sum == 0 && u->left == NULL && u->right == NULL) return true;
        if (u->left && dfs (u->left, sum)) return 1;
        if (u->right && dfs (u->right, sum)) return 1;
        return 0;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        else return dfs (root, sum);
    }
};
