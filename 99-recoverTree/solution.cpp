tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct myNode {
        int val;
        TreeNode *p;
        myNode (int _val, TreeNode *_p) {
            val = _val;
            p = _p;
        }
    };
    vector <myNode> myArr;
    
    void dfs (TreeNode *u) {
        if (u->left != NULL) dfs (u->left);
        myArr.push_back (myNode (u->val, u));
        if (u->right != NULL) dfs (u->right); 
    }
    
    void recoverTree(TreeNode* root) {
        myArr.clear ();
        dfs (root);
        int n = myArr.size ();
        TreeNode *l, *r;
        for (int i = 0; ; i++) {
            if (myArr[i].val > myArr[i+1].val) {
                l = myArr[i].p;
                break;
            }
        }
        for (int i = n-1; ; i--) {
            if (myArr[i].val < myArr[i-1].val) {
                r = myArr[i].p;
                break;
            }    
        }
        swap (l->val, r->val);
    }
};
