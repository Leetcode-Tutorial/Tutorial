class Solution {
public:
    void transit(string &s, int t, int k){
        int med = (k-t)/2 + t;
        for(int i = t; i <= med; i++)
        {
                int j = k-(i-t);
                char tmp;
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;

        }
    }
    string reverseStr(string s, int k) {
        int begin = 0, end;
        while(begin < s.size()){
            end = begin+2*k-1;
            if(begin+k-1 < s.size())
                transit(s, begin, begin+k-1);
            else
                transit(s, begin, s.size()-1);

            begin += 2*k;
        }
        return s;
    }
};