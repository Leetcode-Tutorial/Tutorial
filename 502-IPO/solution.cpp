struct project
{
    int profit;
    int capital;
    bool operator < (const project &a) const {return profit<a.profit;}//按收益从大到小排序
};
bool cmp(project a,project b)
{
    return a.capital<b.capital;//按资产要求从小到大排序
}
int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital)
{
    int n=Profits.size();
    project p[n];
    for(int i=0;i<n;i++)
    {
        p[i].profit=Profits[i];
        p[i].capital=Capital[i];
    }
    sort(p,p+n,cmp);//对所有项目按资产要求从小到大排序
    priority_queue<project> q;
    int f=0,cnt=0;
    int ans=W;
    while(cnt<k)//已取项目数未达到允许的最大项目数
    {
        while(f<n&&p[f].capital<=ans)//还有未放入优先队列的项目并且当前扫描项目资产要求不大于当前已有资产，放入优先队列
        {
            q.push(p[f]);
            f++;
        }
        if(q.empty())break;//优先队列为空，直接结束求解
        project now=q.top();
        q.pop();
        ans=ans+now.profit;
        cnt++;
    }
    return ans;
}
