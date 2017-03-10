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
    int sumNumbers(TreeNode* root) {
        return sum_to_leaf(root, 0);
    }
private:
     int sum_to_leaf(TreeNode* child, int root_to_parent){
         if(!child) return 0;
         int root_to_current = root_to_parent*10 + child->val;
         if(!child->left && !child->right) return root_to_current;
         return sum_to_leaf(child->left, root_to_current) + sum_to_leaf(child->right, root_to_current);
     }
};
