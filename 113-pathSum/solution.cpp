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
    int pos = 0, tmp[10005];
    vector <vector <int> > ans;
    void dfs (TreeNode* u, int sum) {
        sum -= u->val;
        tmp[pos++] = u->val;
        if (u->left == NULL && u->right == NULL && sum == 0) { //找到一条路径
            vector <int> path; path.clear ();
            for (int i = 0; i < pos; i++) { //把路径上所有点保存在vector
                path.push_back (tmp[i]);
            }
            ans.push_back (path); //把这个路径保存到答案中
        }
        if (u->left != NULL) {
            dfs (u->left, sum);
            pos--; //返回的时候把路径上的这个节点除去
        }
        if (u->right != NULL) {
            dfs (u->right, sum);
            pos--;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ans.clear ();
        if (root != NULL) dfs (root, sum);
        return ans;
    }
};
