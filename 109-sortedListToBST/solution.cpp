/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *dfs (ListNode *&p, int n) {//给n个节点的链表构造一个二叉树
        TreeNode *root = NULL;
        int id = 0;
        if (n == 0) return root;
        root = new TreeNode (0);
        //构造左子树
        int tmp = ((n+1)/2);
        if (tmp > 1) {
            root->left = dfs (p, tmp-1);
        }
        //自己
        root->val = p->val;
        //构造右子树
        p = p->next;
        if (tmp < n) {
            root->right = dfs (p, n-tmp);
        }
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root = NULL; ListNode *p = head;
        int n = 0;
        while (p != NULL) {
            p = p->next;
            n++;
        }
        if (!n) return root;
        root = dfs (head, n);
        return root;
    }
};
