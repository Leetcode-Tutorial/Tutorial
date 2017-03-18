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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //关键是得到每一层的结点
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*>Q;
        
        Q.push(root);
        while(!Q.empty())
        {
            vector<int> ans;
           
            int size = Q.size();
            //先判断后减
            while(size-->0)                     //对于当层结点的个数，我遍历完即可，并输出保存到ans中res
            {
                TreeNode* temp = Q.front();
                Q.pop();
                ans.emplace_back(temp->val);
                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                    Q.push(temp->right);
            }
            res.push_back(ans);
            ans.clear();
        }
        return res;
    }
};