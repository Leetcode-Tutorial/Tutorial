class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails(nums.size(), 0);
        int len=0;//记录当前最长递增子序列的长度
        for(const auto& num: nums){
            int i=binarySearch(tails, 0, len, num);//二分搜索确定当前数字 num 在 tails 数组中的位置
            tails[i]=num;//更新 tails 数组
            if(i == len) ++len;//当前数字 num 大于 tails 数组中的所有值
        }
        return len;
    }
private:
    int binarySearch(vector<int>& tails, int start, int end, int val){
        while(start < end){
            int mid=start+(end-start)/2;
            if(tails[mid] < val) start=mid+1;
            else end=mid;
        }
        return start;
    }
};
