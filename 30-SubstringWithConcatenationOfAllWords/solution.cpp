class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        int n=words.size(),len=words[0].size();
        unordered_map<string,int> occ;
        for(int i=0;i<n;i++)
            ++occ[words[i]];
        vector<int> ans;
        for(int i=0;i<len;i++)
        {
            int tot=0;
            unordered_map<string,int> mp(occ);
            for(int j=i;j+len<=s.size();j+=len)
            {
                if(mp.count(s.substr(j,len)))
                {
                    int c=--mp[s.substr(j,len)];
                    if(c==0)    ++tot;
                }
                int start=j-(n-1)*len;
                if(tot==mp.size())    ans.push_back(start);
                if(start>=0&&mp.count(s.substr(start,len)))
                {
                    int c=++mp[s.substr(start,len)];
                    if(c==1)    --tot;
                }
            }
        }
        return ans;
    }
};
