class Solution {
public:
    void rotate_sub(vector<int>& nums,int begin,int end)
    {
        
        int i;
        int end_temp = end;
        int begin_temp = begin;
        for(i = 0;i<(end-begin+1)/2;i++)
        {
            int temp = nums[end_temp];
            nums[end_temp] = nums[begin_temp];
            nums[begin_temp] = temp;
            begin_temp++;
            end_temp--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        //这是我数据结构第一个实验
        if(nums.size()<k)
            k = k % nums.size();
        rotate_sub(nums,0,nums.size()-1);
        rotate_sub(nums,0,k-1);
        rotate_sub(nums,k,nums.size()-1);
        
    }
};