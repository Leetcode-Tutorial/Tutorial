class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        if(root == NULL)
            return result;
        queue<TreeNode*>q;
        
        q.push(root);
        TreeNode* temp;
        while(!q.empty())
        {
            temp = q.front();
            result = temp->val;
            int size = q.size();
            while(size-->0)            //一次性处理一层的值,这个函数就是将一层的节点都处理完了，一层的个数为size
            {
                temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return result;
    }
};