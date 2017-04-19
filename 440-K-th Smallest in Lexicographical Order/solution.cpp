int ans[11],nn[11],base[11];
void get(int now,int tot,int flag,int k)
{
    if(k==0)return;//已经得到需要的数
    int st,ed;
    if(now==0)st=1;//当前处理的是第一位，必须从1开始
    else st=0;//当前不是第一位，可以从0开始
    if(flag==1)ed=nn[now];//前缀和n的前缀相等，该位最大能到n的相同位，否则答案位数小于n的位数
    else ed=10;//前缀不等于n的前缀，该位可为任意数
    int f;
    int reduce;//计算当前前缀的数量
    for(f=st;f<=9;f++)
    {
        if(f>ed||flag<0)reduce=base[now+1];//前缀已经大于n的前缀，答案位数要至少减1
        else if(f==ed)//前缀等于n的前缀，需要分别计算位数相同和不同的情况
        {
            reduce=0;
            for(int i=now+1;i<tot;i++)
            {
                reduce=reduce*10+nn[i];//位数相同的情况（不包括后面全为0）
            }
            reduce=reduce+1+base[now+1];//位数不同和位数相同且后面全为0的情况
        }
        else reduce=base[now];//前缀小于n的前缀，后面的位可以任意
        k=k-reduce;
        //printf("f:%d k:%d\n",f,k);
        if(k<=0)break;//数量已经达到要求
    }
    ans[now]=f;//当前位的答案
    int newflag;//更新flag
    if(flag<0||f>ed)newflag=-1;
    else if(f<ed)newflag=0;
    else newflag=flag;
    get(now+1,tot,newflag,k+reduce-1);//计算下一位
}
int findKthNumber(int n, int k)
{
    int cnt=0;//n的位数
    while(n)
    {
        nn[cnt++]=n%10;
        n=n/10;
    }
    for(int i=0;i<cnt/2;i++)//由于处理的时候是从低位到高位存的，因此需要两两交换
    {
        int tmp=nn[i];
        nn[i]=nn[cnt-1-i];
        nn[cnt-1-i]=tmp;
    }
    for(int i=cnt-1;i>=0;i--)//计算有前缀的情况下i个x（x为0-9或空白）的种类数
    {
        base[i]=base[i+1]*10+1;
        //printf("%d:%d\n",i,base[i]);
    }
    memset(ans,-1,sizeof(ans));
    get(0,cnt,1,k);//得到答案，将每一位存到ans数组
    int res=0;
    for(int i=0;i<cnt;i++)
    {
        if(ans[i]<0)break;//遇到-1表示空白
        res=res*10+ans[i];
    }
    return res;
}
