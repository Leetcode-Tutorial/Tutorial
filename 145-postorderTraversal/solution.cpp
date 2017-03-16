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
    struct node {
        TreeNode *a;
        int b;
    };
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> ans; stack <node> s;
        ans.clear ();
        
        s.push ((node) {root, 1});
        while (!s.empty ()) {
            node u = s.top (); s.pop ();
            if (u.a == NULL) break;
            if (u.b == 2) {
                ans.push_back (u.a->val);
            }
            else {
                s.push ((node) {u.a, u.b+1});
                if (u.a->right != NULL) {
                    s.push ((node) {u.a->right, 1});
                }
                if (u.a->left != NULL) {
                    s.push ((node) {u.a->left, 1});
                }
            }
        }
        return ans;
    }
};
