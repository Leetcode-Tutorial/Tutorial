int leastBricks(vector<vector<int> >& wall)
{
    int store[20005];
    int cnt=0;
    int lenr=wall.size();
    for(int i=0;i<lenr;i++)
    {
        int lenc=wall[i].size();
        int wide=0;
        for(int j=0;j<lenc;j++)
        {
            wide=wide+wall[i][j];
            store[cnt++]=wide;//每个砖块到左边界的距离存下
        }
    }
    sort(store,store+cnt);//从小到大排序
    int ans=lenr,nowcnt=0;
    for(int i=1;i<cnt-lenr;i++)//最后lenr个是墙的右边界，不考虑
    {
        if(store[i]==store[i-1])nowcnt++;//当前砖块和上一个距离相同，累加个数
        else
        {
            ans=min(ans,lenr-nowcnt);//更新答案
            nowcnt=1;
        }
    }
    if(cnt>lenr)ans=min(ans,lenr-nowcnt);//如果cnt和lenr相等说明每行都只有一个墙，否则还要更新一下最后一次统计的答案
    return ans;
}
