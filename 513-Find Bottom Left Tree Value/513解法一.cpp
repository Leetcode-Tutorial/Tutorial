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
    int findBottomLeftValue(TreeNode* root) {
        level = -1;
        inorderTraversal(root, 0);
        return val;
    }
    void inorderTraversal(TreeNode* root, int cur_level){
        if(root->left){
            inorderTraversal(root->left, cur_level+1);
        }
        if(cur_level>level){
            level = cur_level;
            val = root->val;
        }
        if(root->right){
            inorderTraversal(root->right,cur_level+1);
        }
    }
private:
    int level;
    int val;
};