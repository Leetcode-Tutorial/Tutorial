int findMin(vector<int>& nums)
{
    int minm=nums[0];//最小值初始化为第一个元素
    int len=nums.size();
    for(int i=1;i<len;i++)//对数组扫一遍
    {
        minm=min(minm,nums[i]);
    }
    return minm;
}
