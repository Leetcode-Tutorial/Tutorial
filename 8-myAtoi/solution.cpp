class Solution {
public:
    int myAtoi(string str) {
        int s = 0; while (s < str.length () && str[s] == ' ') s++;
        if (s == str.length ()) return 0;
        if (!isdigit (str[s]) && str[s] != '+' && str[s] != '-') {
            return 0;
        }
        
        long long ans = 0;
        int flag = (str[s] == '-' ? -1 : 1);
        if (!isdigit (str[s])) s++;
        for (int i = s; i < str.length () && isdigit (str[i]); i++) {
            ans *= 10;
            ans += (str[i]-'0');
            if (flag == 1 && ans >= 2147483647) return 2147483647;
            else if (flag == -1 && -ans <= -2147483648) return -2147483648;
        }
        ans *= flag;
        return (int)ans;
    }
};
