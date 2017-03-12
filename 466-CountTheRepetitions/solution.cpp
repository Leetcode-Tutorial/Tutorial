class Solution {
public:
    int repeat[105], cnt[105];
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        memset(repeat, 0, sizeof(repeat));
        memset(cnt, 0, sizeof(cnt));
        for (int t = 1, j = 0; t <= n1; ++t) {
            cnt[t] = cnt[t - 1];
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    j = (j + 1) % s2.size();
                    if (j == 0) ++cnt[t];
                }
            }
            for (int st = 0; st < t; ++st) {
                if (repeat[st] == j) {
                    int res = cnt[st] + cnt[st + (n1 - st) % (t - st)] - cnt[st];
                    res += (cnt[t] - cnt[st]) * (n1 - st) / (t - st);
                    return res / n2;
                }
            }
            repeat[t] = j;
        }
        return cnt[n1] / n2;
    }
};