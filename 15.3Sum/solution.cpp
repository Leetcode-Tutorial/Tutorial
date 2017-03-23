class Solution {
public:
    
    vector<vector<int>> twoSum(vector<int> & nums, int start, int end) {
        vector<vector<int>> ans;
        int sum = 0 - nums[start - 1];
        
        while(start < end) {
            vector<int>temp;
            temp.push_back(0 - sum);
            if(nums[start] + nums[end] == sum) {
                temp.push_back(nums[start]);
                temp.push_back(nums[end]);
                start ++;
                while(start < end && nums[start] == nums[start - 1]) {
                    start ++;
                }
                end --;
                while(start < end && nums[end] == nums[end + 1]) {
                    end --;
                }
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
            if(temp.size() != 1) {
                ans.push_back(temp);
            }
        }
        return ans;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 0; i < len - 2; i ++) {
            while(i > 0 && i < len - 2 && nums[i] == nums[i-1]) {
                i ++;
            }
            vector<vector<int>> temp = twoSum(nums, i + 1, len - 1);
            if(temp.size() != 0) {
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
        }
        return ans;
    }
};
