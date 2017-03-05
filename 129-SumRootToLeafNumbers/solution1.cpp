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
    int sumNumbers(TreeNode* root) {
        //init
        sums = 0;
        value_list.clear();
        //start preorder traversal
        preorderTraversal(root);
        return sums;
    }
private:
    void preorderTraversal(TreeNode* root){
        if(!root) return;
        value_list.emplace_back(root->val);
        //visit leaf node, i.e, find a new path from root to leaf
        if(!root->left && !root->right) toNumeric();
        //proceed left subtree
        preorderTraversal(root->left);
        //proceed right subtree
        preorderTraversal(root->right);
        //remove current node after visiting current subtree
        value_list.pop_back();
        return;
    }
    //convert value list to integer
    //add up current path sum to total path sum
    void toNumeric(){
        int sum=0;
        for(const auto& num: value_list){
            sum *= 10;
            sum += num;
        }
        sums += sum;
    }
    //the sum of found paths from root to leaf
    int sums;
    //record current path
    vector<int> value_list;
};
