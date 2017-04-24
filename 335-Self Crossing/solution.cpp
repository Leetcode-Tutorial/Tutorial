bool isSelfCrossing(vector<int>& x)
{
    int len=x.size();
    bool isreduce=false;//序列是否进入降序的标志
    for(int i=2;i<len;i++)
    {
        if(!isreduce)//序列还处于升序状态
        {
            if(x[i]<=x[i-2])//出现非升序的元素，进入降序状态
            {
                isreduce=true;
                if((i>=4&&x[i-4]+x[i]>=x[i-2])||(i==3&&x[i]==x[i-2]))x[i-1]=x[i-1]-x[i-3];//两个注意的地方
            }
        }
        else//序列已处于降序状态
        {
            if(x[i]>=x[i-2])return true;//出现非降序的元素，存在一个点经过了多次
        }
    }
    return false;//不存在一个点经过多次
}
