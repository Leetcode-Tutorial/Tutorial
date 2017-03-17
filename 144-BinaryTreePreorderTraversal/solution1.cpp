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
        vector<int> value_list;
        if(!root) return value_list;
        //record current node
        value_list.emplace_back(root->val);
        //obtain the preorder traversal of left subtree
        vector<int> left_list = preorderTraversal(root->left);
        //obtain the preorder traversal of right subtree
        vector<int> right_list = preorderTraversal(root->right);
        //combine left and right traversal result
        //the form of preorder traversal:
        //[ current_node     left_subtree_traversal     right_subtree_traversal ]
        value_list.insert(value_list.end(), left_list.begin(), left_list.end());
        value_list.insert(value_list.end(), right_list.begin(), right_list.end());
        //return the preorder traversal of the subtree with the current node as the root node
        return value_list;
    }
};
