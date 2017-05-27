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
    bool dfs (TreeNode *root1, TreeNode *root2) { //判断两棵树是不是镜面对称
        if (root1 == NULL && root2 == NULL) return 1;
        if (root1 == NULL || root2 == NULL) return 0;
        if (root1->val != root2->val) return 0;
        return dfs (root1->left, root2->right) && dfs (root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (dfs (root, root)) return true;
        else return false;
    }
};
