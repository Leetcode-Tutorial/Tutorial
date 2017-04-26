vector<int> get(vector<int>& num,int tot,int need)
{
    vector<int> res;
    if(need==0)return res;//该数组不需要选任何数
    stack<int> digit,id;
    int nowcnt=0;
    for(int i=0;i<tot;i++)
    {
        while(tot-i>need-nowcnt&&!digit.empty()&&num[i]>digit.top())//后面的数不必全选并且栈非空并且当前数字大于栈顶元素，弹栈
        {
            res.erase(res.end()-1);
            digit.pop();
            id.pop();
            nowcnt--;
        }
        if(nowcnt<need)//栈不满，入栈
        {
            res.push_back(num[i]);
            digit.push(num[i]);
            id.push(i);
            nowcnt++;
        }
    }
    return res;
}
bool check(vector<int>& nums1,int now1,int m,vector<int>& nums2,int now2,int n)
{
    while(now1<m&&now2<n)//从两个数组当前所指元素开始检查
    {
        if(nums1[now1]!=nums2[now2])return nums1[now1]>nums2[now2];//碰到不相等的，看是否第一个元素大
        now1++;
        now2++;
    }
    return now2==n;//之前扫描的都是相等的，看是否第二个数组已检查完
}
void getans(vector<int>& nums1,int m,vector<int>& nums2,int n,char ans[])
{
    int now1=0,now2=0,now=0;
    while(now1<m||now2<n)//两个数组选出的数字还没排完
    {
        if(check(nums1,now1,m,nums2,now2,n))//判断是否选第一个数组的数字
        {
            ans[now]=nums1[now1]+'0';
            now++;
            now1++;
        }
        else
        {
            ans[now]=nums2[now2]+'0';
            now++;
            now2++;
        }
    }
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
    int m=nums1.size(),n=nums2.size();
    int init1,init2,cnt;//初始时第一个数组取的个数、第二个数组取的个数、之后要枚举的次数
    if(k>=m)//以下是分情况讨论确定上述值
    {
        init1=m;
        init2=k-m;
        if(k>=n)cnt=n-(k-m);
        else cnt=m;
    }
    else
    {
        init1=k;
        init2=0;
        if(k>=n)cnt=n;
        else cnt=k;
    }
    vector<int> now1=get(nums1,m,init1);//在第一个数组中选
    vector<int> now2=get(nums2,n,init2);//在第二个数组中选
    char ans[k+1];
    ans[k]=0;
    getans(now1,init1,now2,init2,ans);//两个数组选的数字合并
    char anss[k+1];
    anss[k]=0;
    for(int i=1;i<=cnt;i++)//枚举两个数组中选的个数并求解
    {
        now1=get(nums1,m,init1-i);
        now2=get(nums2,n,init2+i);
        getans(now1,init1-i,now2,init2+i,anss);
        if(strcmp(ans,anss)<0)strcpy(ans,anss);//比较答案是否更优
    }
    vector<int> res;
    for(int i=0;i<k;i++)
    {
        res.push_back(ans[i]-'0');
    }
    return res;
}
