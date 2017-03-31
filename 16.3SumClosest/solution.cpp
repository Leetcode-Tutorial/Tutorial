class Solution {
public:
    
    void twoSum(vector<int> & nums, int start, int end, int target) {

        int sum = target - nums[start - 1];
        
        while(start < end) {
            if(abs(ans - target) > abs(nums[start] + nums[end] - sum)) {
                ans = nums[start] + nums[end] - sum + target;
            }
            
            if(nums[start] + nums[end] == sum) {
                ans = target;
                return ;
            } else if(nums[start] + nums[end] < sum) {
                start ++;
                while(start < end && nums[start] == nums[start - 1]) {
                    start ++;
                }
            } else if(nums[start] + nums[end] > sum) {
                end --;
                while(start < end && nums[end] == nums[end + 1]) {
                    end --;
                }
            }
        }
    }
    
    int threeSumClosest(vector<int>& nums, int target)  {
        //each input would have exactly one solution, so nums.size() >= 3
        ans = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 0; i < len - 2; i ++) {
            while(i > 0 && i < len - 2 && nums[i] == nums[i-1]) {
                i ++;
            }
            twoSum(nums, i + 1, len - 1, target);
        }
        return ans;
    }
private:
    int ans;
};
