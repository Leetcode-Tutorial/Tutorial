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
    int n, pos[10005];
    map <int, int> mp;
    TreeNode* dfs (int l1, int r1, int l2, int r2, vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = new TreeNode (preorder[l1]);
        int mid = mp[root->val]; //找到根在中序遍历中的位置
        int lsize = mid-l2, rsize = r2-mid; //左右子树的size
        if (lsize) root->left = dfs (l1+1, l1+lsize, l2, l2+lsize-1, preorder, inorder);
        if (rsize) root->right = dfs (l1+lsize+1, l1+lsize+rsize, mid+1, mid+rsize, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size ();
        if (n == 0) return NULL;
        mp.clear ();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        TreeNode *root = dfs (0, n-1, 0, n-1, preorder, inorder);
        return root;
    }
};
