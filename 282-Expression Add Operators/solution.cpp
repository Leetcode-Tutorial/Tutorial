void get(vector<string> &res,int cur,int len,string ans,string num,long long now,long long last,int target)
{
    if(cur==len)//字符串已取完
    {
        if(now==target)res.push_back(ans);//结果等于目标值，将构造出的串加入答案
    }
    else
    {
        for(int i=cur;i<len&&(num[cur]!='0'||i==cur);i++)//从当前位置开始取，如果第一位为0则只能取一位
        {
            long long nownum=0;
            string s="";
            for(int j=cur;j<=i;j++)//将当前取的转为数
            {
                nownum=nownum*10+num[j]-'0';
                s=s+num[j];
            }
            if(cur==0)get(res,i+1,len,ans+s,num,nownum,nownum,target);//从第0位取的是第一个数，不用添加符号
            else
            {
                get(res,i+1,len,ans+"+"+s,num,now+nownum,nownum,target);//添加+
                get(res,i+1,len,ans+"-"+s,num,now-nownum,-nownum,target);//添加-
                get(res,i+1,len,ans+"*"+s,num,now-last+last*nownum,last*nownum,target);//添加*
            }
        }
    }
}
vector<string> addOperators(string num, int target)
{
    vector<string> res;
    int len=num.size();
    if(len!=0)get(res,0,len,"",num,0,0,target);//字符串不为空的时候进行dfs
    return res;
}
