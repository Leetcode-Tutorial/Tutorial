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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //其实下面就包括5种情况
        if(p==NULL && q==NULL)
            return true;
        else if(p==NULL && q!=NULL)    //如果p为空，但是q不为空，返回false
            return false;
        else if(p!=NULL && q==NULL)    //如果p不为空,q为空，返回false
            return false;
        else if(p->val != q->val)      //如果当前p节点的值与q节点的值不同，返回false
            return false;
        else
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);           //左右子树都要相同
    }
};
