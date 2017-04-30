class Solution {
public:
    void reverseWords(string &s) {
        if(s == "") return ;
        auto it1 = s.begin(), it2 = s.begin();
        while(it2 != s.end()&&*it2 == ' ') it2++;//cut the left ' '
        while(it2 != s.end()){
            *it1++ = *it2++;
            if(it2 != s.end()&&*it2 == ' '){
                *it1++ = *it2++;
                while(it2 != s.end()&&*it2 == ' ')//cut the middle ' '
                    it2++;
            }
        }
        if(it1 != s.begin()&&*(it1-1) == ' ') it1--;//cut the right ' '
        s.erase(it1, s.end());

        reverse(s.begin(), s.end());//reverse the string
        it1 = it2 = s.begin();
        while(it2 != s.end()){
            if(*it2 != ' ') {
                it2++;
                continue ;
            }
            reverse(it1, it2);//reverse word by word
            it1 = ++it2;
        }
        reverse(it1, it2);
    }
};
