class Solution {
         //该题利用队列进行层次遍历
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>result;
        if(root == NULL)               //如果树为空，就返回空vector.做任何题目的时候，都应该考虑特殊情况
            return result;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        
        while(!q.empty())
        {
            int size = q.size();
            int maxn = INT_MIN;        //来记录每一层最后的结果
            
            //一次性取出一层的个数节点来处理
            while(size-->0)
            {
                temp = q.front();
                q.pop();
                maxn = max(maxn,temp->val);   //处理了当前节点了
                
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            result.push_back(maxn);
        }
        return result;
    }
};