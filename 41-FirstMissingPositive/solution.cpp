class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, j = 0;
        for( ; i < nums.size(); i++)        //预处理，nums[0 ~ j-1]为所有的j个正整数
            if(nums[i] > 0) nums[j++] = nums[i];
        for(int i = 0; i < j; i++){
            int n = nums[i]&0x7fffffff;        //取出所存的正整数
            if(n <= j) nums[n-1] |= 0x80000000;//标记该正整数的存在
        }
        int ans = 0;    //遍历查找第一个不存在的正整数
        while(ans < j && (nums[ans]&0x80000000)) ans++;
        return ans+1;
    }
};
