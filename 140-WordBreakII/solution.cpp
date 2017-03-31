class Solution
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> word;
        for(auto str:wordDict)
            word.insert(str);

        int n=s.size();
        vector<vector<int>> dp(n+1);
        dp[0].push_back(0);
        s=' '+s;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                if(dp[j-1].size()&&word.count(s.substr(j,i-j+1)))
                    dp[i].push_back(j);
        vector<string> ans;
    }
    void dfs(string str,vector<vector<int>> &dp, string ori,vector<string> &ans,int idx)
    {
        if(left==0)
        {
            ans.push_back(str);
            return;
        }
        for(auto nid:dp[idx])
        {
            string nstr;
            if(str.empty())    nstr=ori.substr(nid,idx-nid+1);
            else     nstr=ori.substr(nid,idx-nid+1)+" "+str;
            dfs(nstr,dp,ori,ans,nid-1);
        }
    }
};
