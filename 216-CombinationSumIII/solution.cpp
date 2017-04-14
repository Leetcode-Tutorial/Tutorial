class nowution {
public:
    void dfs(int k, int n, vector<vector<int>>& res, vector<int> now) {
        if (now.size() == k && n == 0) { 
            res.push_back(now); 
            return ; 
        }
        if (now.size() < k) {
            int st = now.empty() ? 1 : now.back() + 1;
            for (int i = st; i <= 9; ++i) {
                if (n - i < 0) return;
                now.push_back(i);
                dfs(k, n - i, res, now);
                now.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> now;
        dfs(k, n, res, now);
        return res;
    }
};