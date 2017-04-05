class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n==0) return ans;
        ans.push_back(1);
        int down=1;
        for(int T=1; T<n; T++)
        {
            for(int i=down; i!= -1; i--)
            {
                int x = ans[i] | (1<<T);//产生新的数字
                ans.push_back(x);
            }
                down = ans.size();//重新确定当前的下界
        }
        return ans;
    }
};
