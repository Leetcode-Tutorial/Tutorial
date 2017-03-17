class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        int n=wordList.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)    mp[wordList[i]]=i;

        int begin;
        if(mp.find(beginWord)==mp.end())
        {
            wordList.push_back(beginWord);
            ++n;
            mp[wordList[n-1]]=n-1;
            begin=n-1;
        }
        else
            begin=mp[beginWord];
        if(mp.find(endWord)==mp.end())
            return {};
        int end=mp[endWord];

        vector<vector<int>> g(n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(canChange(wordList[i],wordList[j]))
                    g[i].push_back(j),g[j].push_back(i);

        const int inf=n*10;
        vector<int> dis(n,inf);
        dis[begin]=0;
        queue<int> que;
        que.push(begin);
        while(!que.empty())
        {
            int u=que.front();que.pop();
            for(int i=0;i<g[u].size();i++)
            {
                int v=g[u][i];
                if(dis[v]>dis[u]+1)
                {
                    dis[v]=dis[u]+1;
                    que.push(v);
                }
            }
        }
        if(dis[end]==inf)    return {};

        cur.push_back(wordList[end]);
        genAns(end,g,dis,wordList);
        for(int i=0;i<ans.size();i++)
            reverse(ans[i].begin(),ans[i].end());
        return ans;
    }
    vector<vector<string>> ans;
    vector<string> cur;
    void genAns(int u,vector<vector<int>> &g,vector<int> &dis,vector<string> &wordList)
    {
        if(dis[u]==0)
        {
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(dis[v]+1==dis[u])
            {
                cur.push_back(wordList[v]);
                genAns(v,g,dis,wordList);
                cur.pop_back();
            }
        }
    };
    bool canChange(string &a,string &b)
    {
        int tot=0;
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i])
                ++tot;
        return tot==1;
    }
};
