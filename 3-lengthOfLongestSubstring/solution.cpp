class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool vis[233] = {0}; int n = s.length ();
        int l = 0, r = 0;
        while (r < n && !vis[s[r]]) {
            vis[s[r]] = true;
            r++;
        }
        int ans = r-l;
        while (l < n) {
            while (r < n && !vis[s[r]]) {
                vis[s[r]] = true;
                r++;
            }
            ans = max (ans, r-l);
            vis[s[l]] = 0;
            l++;
        }
        return ans;
    }
};
