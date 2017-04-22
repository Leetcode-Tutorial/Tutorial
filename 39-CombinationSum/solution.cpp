class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        result.clear();
        helper(candidates, vector<int>(), 0, target);
        return result;
    }
private:
    void helper(vector<int>& candidates, vector<int> cur, int start, int target){
        if(target==0) {
            result.emplace_back();
            result.back().assign(cur.begin(), cur.end());
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(target<candidates[i]) break;
            cur.emplace_back(candidates[i]);
            helper(candidates, cur, i, target-candidates[i]);
            cur.pop_back();
        }
    }
    vector<vector<int>> result;
};
