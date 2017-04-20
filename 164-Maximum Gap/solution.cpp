int maximumGap(vector<int>& nums)
{
    int len=nums.size();
    if(len<2)return 0;//数组元素个数不超过2
    int num[len];
    vector<int> id[10][10];//用于存每次基数排序后的元素下标
    for(int i=0;i<len;i++)
    {
        num[i]=nums[i];//将所有元素复制一份，方便每次排序时比较
        id[0][num[i]%10].push_back(i);//按个位排序，将下标存到对应数组
        num[i]=num[i]/10;//将个位丢弃，为十位比较做准备
    }
    for(int i=1;i<10;i++)//依次从十位开始往高位比较
    {
        for(int j=0;j<10;j++)//从前一次比较最小的元素开始
        {
            int nowlen=id[i-1][j].size();
            for(int k=0;k<nowlen;k++)
            {
                int nowid=id[i-1][j][k];//取id
                id[i][num[nowid]%10].push_back(nowid);//将下标存到对应数组
                num[nowid]=num[nowid]/10;//将当前位丢弃，为下一位比较做准备
            }
        }
    }
    int last=-1,ans=0;
    for(int i=0;i<10;i++)
    {
        int nowlen=id[9][i].size();
        for(int j=0;j<nowlen;j++)
        {
            int nowid=id[9][i][j];
            if(last==-1)last=nums[nowid];//当前是最小的数
            else ans=max(ans,nums[nowid]-last);//更新最大的差
            last=nums[nowid];
        }
    }
    return ans;
}
