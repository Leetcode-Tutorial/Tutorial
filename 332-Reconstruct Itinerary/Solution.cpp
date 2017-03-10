class Solution{
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets)
    {
        vector<string> ans;
        Link.clear();
        for(auto &tmp: tickets)
            Link[tmp.first].push(tmp.second);
        dfs("JFK",ans);
        return vector<string>(ans.rbegin(),ans.rend());//将当前答案序列进行翻转以得到我们所需要的最终答案
    }
    void dfs(string Cur, vector<string> &ans)
    {
        /*
            Cur中所存储的是当前所在的名称
            以vector容器来存储最终的答案序列
        */
        while(!Link[Cur].empty())
        {
            string tmp = Link[Cur].top(); //取出当前的堆顶城市名称
            Link[Cur].pop();
            dfs(tmp,ans);
        }
        ans.push_back(Cur);//当 当前点所能千万的点都被访问过时， 将其加入答案序列当中
    }
    private:
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> Link;//以小根堆的形式来存储每个城市所能够到达的另外一个城市,\
        在堆顶的一定是当前所能够到达的字典序最小的城市名称
}
