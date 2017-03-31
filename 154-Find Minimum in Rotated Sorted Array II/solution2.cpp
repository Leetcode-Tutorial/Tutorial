int findMin(vector<int>& nums)
{
    int len=nums.size();
    for(int i=1;i<len;i++)
    {
        if(nums[i]<nums[i-1])return nums[i];//当前元素比前一个小，找到中心，当前元素即为最小
    }
    return nums[0];//整个序列依旧是递增的，则第一个是最小的
}
