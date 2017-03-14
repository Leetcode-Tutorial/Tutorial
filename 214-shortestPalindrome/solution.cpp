class Solution {
public:
    string shortestPalindrome(string s) {
        reverse (s.begin (), s.end ());
        string h = s; 
        reverse (h.begin (), h.end ());
        unsigned long long hash1 = 0, hash2 = 0, seed = 131, bit = 1;
        int n = s.length ();
        int len = 0; //s的后缀和h的前缀的最长匹配长度
        for (int i = 0; i < n; i++, bit *= seed) {
            hash1 = hash1*seed+s[n-1-i]-'a'+1;
            hash2 = hash2+bit*(h[i]-'a'+1);
            if (hash1 != hash2) {
                continue;
            }
            else {
                len = i+1;
            }
        }
        for (int i = len; i < n; i++) {
            s += h[i];
        }
        return s;
    }
};
