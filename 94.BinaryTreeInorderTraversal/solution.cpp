/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNodeVisit{
    bool visit;
    TreeNode * node;
    TreeNodeVisit* left;
    TreeNodeVisit* right;
    TreeNodeVisit(TreeNode * temp): visit(false), node(temp), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        stack<TreeNodeVisit*> inorder;
        if(root == NULL) {
            return ans;
        }
        inorder.push(new TreeNodeVisit(root));
        
        while(!inorder.empty()) {
            TreeNodeVisit* temp = inorder.top(); // 取一个节点
            
            if(temp->node->left != NULL && (temp->left == NULL || temp->left->visit == false)) {
                temp->left = new TreeNodeVisit(temp->node->left);
                inorder.push(temp->left);
            } else {
                ans.push_back(temp->node->val);  // 记录本节点的值
                inorder.pop();  // 本节点出栈
                temp->visit = true;
                if(temp->node->right != NULL && (temp->right == NULL || temp->right->visit == false)) {
                    temp->right = new TreeNodeVisit(temp->node->right);
                    inorder.push(temp->right);
                }
            }
        }
        return ans;
    }
};
