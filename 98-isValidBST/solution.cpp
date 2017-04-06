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
    int Max[10005], Min[10005];//以每个节点为根的子树中最大/最小值是多少
    int l[10005], r[10005], tot; //每个节点左孩子/右孩子的编号 一共遍历了多少个节点
    
    bool dfs (TreeNode *u) { //以u为根的子树是否合法
        if (u == NULL) return 1;
        int cur = ++tot; //当前根节点的编号
        Min[cur] = Max[cur] = u->val;
        int cur_left = cur+1; //左孩子的编号是自身编号+1
        if (u->left != NULL) {
            if (!dfs (u->left)) return 0;
            if (u->val <= Max[cur_left]) { //自身的值小于等于左子树的最大值
                return 0;
            }
            Min[cur] = min (Min[cur], Min[cur_left]);
            Max[cur] = max (Max[cur], Max[cur_left]);
        }
        int cur_right = tot+1; //右孩子的编号 
        if (u->right != NULL) {
            if (!dfs (u->right)) return 0;
            if (u->val >= Min[cur_right]) { //自身的值大于等于右子树的最小值
                return 0;
            }
            Min[cur] = min (Min[cur], Min[cur_right]);
            Max[cur] = max (Max[cur], Max[cur_right]);
        }
        return 1;
    }
    bool isValidBST(TreeNode* root) {
        tot = 0;
        return (dfs (root));
    }
};
