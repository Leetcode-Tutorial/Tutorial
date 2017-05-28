class Solution {
public:
    int findLUSlength(string a, string b) {
        int len_a = a.length(),len_b = b.length();
        if(len_a != len_b)
            {
                return max(len_a,len_b);
            }
        else
        {
            if(a==b)                           //如果相等，说明没有满足要求的
                return -1;
            else
                return len_a;
        }
    }
};