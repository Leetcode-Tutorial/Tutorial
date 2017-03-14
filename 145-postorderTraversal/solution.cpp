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
    vector <int> answer;
    void dfs (TreeNode *root) {
        if (root == NULL) return ;
        if (root->left != NULL) dfs (root->left);
        if (root->right != NULL) dfs (root->right);
        answer.push_back (root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        answer.clear ();
        dfs (root);
        return answer;
    }
};
