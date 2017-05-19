string optimalDivision(vector<int>& nums)
{
    int len=nums.size();
    string ans="";
    char store[4];
    for(int i=0;i<len;i++)
    {
        int cnt=0;
        while(nums[i])//把每个数每一位拆开，变成字符形式
        {
            store[cnt++]=nums[i]%10+'0';
            nums[i]=nums[i]/10;
        }
        for(int j=cnt-1;j>=0;j--)//倒序加入答案
        {
            ans=ans+store[j];
        }
        if(i<len-1)ans=ans+"/";//不是最后一个数，添加除号
        if(len>2)//如果不超过两个数就不用添加括号
        {
            if(i==len-1)ans=ans+")";//最后一个数后面加右括号
            else if(i==0)ans=ans+"(";//头一个数后面加左括号
        }
    }
    return ans;
}
