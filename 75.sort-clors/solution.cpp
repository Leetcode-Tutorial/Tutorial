class Solution {
public:
    void sortColors(vector<int>& nums) {
        //这里我们是不允许使用sort函数
        //我可以采取俩边夹的过程，碰到0从左到右，碰到2从右到左即可
        //然后最终完成的就是排序好的
        int len = nums.size();
        int i_0 = 0,j_2 = len-1;
        for(int i = 0;i<len;i++)
        {
           while(i<=j_2&&nums[i]==2)
           {
               swap(nums[i],nums[j_2--]);
           }
           while(i>=i_0&&nums[i]==0)
           {
               swap(nums[i],nums[i_0++]);     //就是切记你换过来还可能是0，所以需要循环
           }
        }
    }
};