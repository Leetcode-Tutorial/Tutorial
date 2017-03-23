class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        vector<int> nums;
        queue<TreeNode *> que;
        TreeNode *p = root;
        que.push(p);
       
        int level  = 0; // curent level
        while(!que.empty()){
            nums.resize(0);
            level += 1;                                                //确定是哪一层，分别确定是正序还是逆序输出yi'g
            int queSize = que.size();
            for(int i = 0; i < queSize; i++ ) {                        //在该层进行遍历，然后将左右孩子加入进行
                p = que.front();
                nums.push_back(p->val);
                que.pop();
                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);
            }
            if(level % 2 == 0) reverse(nums.begin(),nums.end());
            res.push_back(nums);
        }
        return  res;         
    }
};
