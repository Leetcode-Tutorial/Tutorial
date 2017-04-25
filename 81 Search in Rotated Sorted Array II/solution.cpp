class Solution {
public:
bool search(vector<int>& nums, int target) {
//扫描一遍肯定可以，那么放在这里不是这么简单的,是希望我们用log级别的
//方法一我们先用师兄的做法，先二分找到那个边界，然后分开进行二分查找即可~
//方法二用下面这种方法

int len = nums.size();
int left = 0,right = len-1;
while(left<=right)
{
int mid = (left+right)/2;
if(nums[mid] == target)
{
return true;
}
if(nums[mid]==nums[left])
left++;
else if(nums[mid]>=nums[left]) //砍掉的一半一定要是可以砍掉的
{
if(target<=nums[mid]&&target>=nums[left])
right = mid-1;
else
left = mid+1;

}
else
{
if(nums[mid]< target&&target<=nums[right])
left = mid+1;
else
right = mid-1;
}
}
return false;
}
};