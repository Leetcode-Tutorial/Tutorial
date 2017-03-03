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
    vector<int> preorderTraversal(TreeNode* root) {
        //init
        value_list.clear();
        //start preorder traversal
        preorder(root);
        return value_list;
    }
private:
    void preorder(TreeNode* root){
        if (!root)  return;
        //record current node
        value_list.emplace_back(root->val);
        //visit left subtree
        preorder(root->left);
        //visit right subtree
        preorder(root->right);
        return;
    }
    //record current path
    vector<int> value_list;
};
