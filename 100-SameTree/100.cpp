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
        //��ʵ����Ͱ���5�����
        if(p==NULL && q==NULL)
            return true;
        else if(p==NULL && q!=NULL)    //���pΪ�գ�����q��Ϊ�գ�����false
            return false;
        else if(p!=NULL && q==NULL)    //���p��Ϊ��,qΪ�գ�����false
            return false;
        else if(p->val != q->val)      //�����ǰp�ڵ��ֵ��q�ڵ��ֵ��ͬ������false
            return false;
        else
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);           //����������Ҫ��ͬ
    }
};
