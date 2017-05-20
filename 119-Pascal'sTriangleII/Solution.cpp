class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int ret = 1;
        vector<int> ans = {ret};
        for(int i = 1; i <= rowIndex; i++){
            ret = ret*(rowIndex-i+1LL)/i;
            ans.push_back(ret);
        }
        return ans;
    }
};
