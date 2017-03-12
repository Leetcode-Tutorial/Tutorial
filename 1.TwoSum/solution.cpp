class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        unordered_map<int, int>myMap;
        unordered_map<int, int>::iterator it;

        int len = nums.size();
        for(int i = 0; i < len; i ++) {
            it = myMap.find(target - nums[i]);
            if(it != myMap.end()) {
                ans.push_back(it->second);
                ans.push_back(i);
                return ans;
            }
            myMap[nums[i]] = i;
        }
        return ans;
    }
};
