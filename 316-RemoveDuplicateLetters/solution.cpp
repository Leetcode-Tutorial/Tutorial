class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n=s.size();
        vector<int> c(26,0),in(26,0);
        for(int i=0;i<n;i++)    ++c[s[i]-'a'];
        string ans;
        for(int i=0;i<n;i++)
        {
            --c[s[i]-'a'];
            if(in[s[i]-'a'])    continue;
            while(ans.size()&&s[i]<ans.back()&&c[ans.back()-'a'])
                in[ans.back()-'a']=0,ans.pop_back();
            ans.push_back(s[i]);
            in[s[i]-'a']=1;
        }
        return ans;
    }
};
