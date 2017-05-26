class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map <int,int> mp;
        int sum = 0, res = 0; 
        mp[0]++; 
        for(int i = 0; i < (int)nums.size(); i++){
            sum += nums[i];
            res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};