int findMin(vector<int>& nums)
{
    int len=nums.size();
    int left=0,right=len-1;//初始化左右指针
    while(left<right)//左右指针不重合
    {
        int mid=(left+right)/2;//中间的位置
        if(nums[mid]==nums[right])right--;//中间位置元素和右端点元素相等，右端点减1
        else if(nums[mid]<nums[right])right=mid;//中间位置元素小于右端点元素，修改右端点
        else left=mid+1;//中间位置元素大于右端点元素，修改左端点
    }
    return nums[left];
}
