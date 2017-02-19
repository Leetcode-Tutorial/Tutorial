class Solution {
public:
    bool isSubsequence(string s, string t) {
        //俩个指针都往前走
        if(s.length()==0)
            return true;        //空字符串是任何字符串的子串
        int i = 0,j = 0;
        bool res = false;
        int s_len = s.length(),t_len = t.length();
        while(j < t_len)
        {
            if(t[j] == s[i])
            {
                i++;
                if(i==s_len)
                {
                    res = true;
                    break;
                }
            }
            j++;         //无论t[j]是否等于s[i]，j都要加1
        }
        return res;
    }
};
