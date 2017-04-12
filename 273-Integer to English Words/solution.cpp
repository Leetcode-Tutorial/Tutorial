string get(int num)
{
    string ge[20]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};//不超过19的正整数表达
    string shi[10]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};//十位不小于2的表达
    string ans="";
    int gewei=num%10,shiwei=(num/10)%10,baiwei=num/100;//把数分成个位、十位、百位
    int pre=0;//先前是否有非0数的标记
    if(baiwei!=0)//百位不为0
    {
        pre=1;
        ans=ans+ge[baiwei]+" Hundred";
    }
    if(shiwei>1)//十位大于1，单独表达
    {
        if(pre)ans=ans+" ";//先前已有非0数，添加空格
        pre=1;
        ans=ans+shi[shiwei];
    }
    if(shiwei==1||gewei!=0)//十位和个位组成的数为小于20的正数时，一起表达
    {
        if(shiwei==1)gewei=gewei+10;
        if(pre)ans=ans+" ";//先前已有非0数，添加空格
        ans=ans+ge[gewei];
    }
    return ans;
}
string numberToWords(int num)
{
    if(num==0)return "Zero";//数为0，直接返回
    string rear[4]={""," Thousand"," Million"," Billion"};//每一级的末尾单位
    int nums[4];
    for(int i=0;i<4;i++)//给数分级
    {
        nums[i]=num%1000;
        num=num/1000;
    }
    string ans="";
    int pre=0;//先前是否有非0数的标记
    for(int i=3;i>=0;i--)
    {
        if(!nums[i])continue;//该级为0
        if(pre)ans=ans+" ";//先前已有非0数，添加空格
        pre=1;
        ans=ans+get(nums[i])+rear[i];//添加该级的表达以及末尾单位
    }
    return ans;
}
