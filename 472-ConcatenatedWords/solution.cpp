class Solution {
public:
    bool dp[600005];
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector <string> ans;
        set <string> st;
        auto cmp = [&](const string& a, const string& b) {return a.length() < b.length();};
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        for (int i = 0; i < n; i++) {
            int len = words[i].length();
            if (!len) continue;
            for (int j = 0; j <= len; j++) dp[j] = false;
            dp[0] = true;
            for (int j = 0; j < len; j++) {
                for (int k = 0; k < len; k++) {
                    if (dp[k] && st.count(words[i].substr(k, j + 1 - k)) > 0) {
                        dp[j + 1] = true; 
                        break;
                    }
                }
            }
            if (dp[len]) ans.push_back(words[i]);
            st.insert(words[i]);
        }
        return ans;
    }
};