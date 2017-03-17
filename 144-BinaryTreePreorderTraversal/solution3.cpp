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
        //record result
        vector<int> value_list;
        vector<TreeNode*> stack;
        while(root || !stack.empty()){
            while(root){
                value_list.emplace_back(root->val);
                stack.emplace_back(root->right);
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
        }
        return value_list;
    }
};
