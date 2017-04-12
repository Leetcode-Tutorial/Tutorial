class Solution {
public:
    
    vector<vector<int>> twoSum(vector<int> & nums, int start, int end, int target, int l1, int l2) {
        vector<vector<int>> ans;
        int sum = target - l1 - l2;
        
        while(start < end) {
            if(nums[start] + nums[end] == sum) {
                vector<int>temp;
                temp.push_back(l1);
                temp.push_back(l2);
                temp.push_back(nums[start]);
                temp.push_back(nums[end]);
                ans.push_back(temp);
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
        }
        return ans;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        
        for(int i = 0; i < len - 3; i ++) {
            for(int j = i + 1; j < len - 2; j ++) {
                vector<vector<int>> temp = twoSum(nums, j + 1, len - 1, target, nums[i], nums[j]);
                if(temp.size() != 0) {
                    ans.insert(ans.end(), temp.begin(), temp.end());
                }
                while(j + 1 < len -2 && nums[j] == nums[j + 1]) {
                    j ++;
                }
            }
            while(i + 1 < len - 3&& nums[i] == nums[i + 1]) {
                i ++;
            }
        }
        return ans;
    }
};
