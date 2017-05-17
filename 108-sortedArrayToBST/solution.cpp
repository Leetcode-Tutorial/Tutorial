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
    TreeNode* solve (vector<int>& nums, int l, int r) {
        TreeNode *u = NULL; 
        int pos = (l+r+1)/2;
        u = new TreeNode (nums[pos]);
        if (pos > l) {
            u->left = solve (nums, l, pos-1);
        }
        if (pos < r) {
            u->right = solve (nums, pos+1, r);
        }
        return u;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = NULL;
        if (nums.size () == 0) return root;
        root = solve (nums, 0, nums.size ()-1);
        return root;
    }
};
