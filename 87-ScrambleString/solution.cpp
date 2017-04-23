class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if(s1==s2)    return true;
        if(s1.size()!=s2.size())    return false;
        vector<int> count(26);
        for(auto v:s1)
            ++count[v-'a'];
        for(auto v:s2)
            --count[v-'a'];
        for(auto v:count)
            if(v)
                return false;
        for(int i=1;i<s1.size();i++)
        {
            bool flag=isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i));
            if(flag)    return true;
            flag=isScramble(s1.substr(0,i),s2.substr(s1.size()-i))&&isScramble(s1.substr(i),s2.substr(0,s1.size()-i));
            if(flag)    return true;
        }
        return false;
    }
};
