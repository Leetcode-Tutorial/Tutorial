class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        map<int,int> mp;
        for (int i = 0; i < nums.size(); i++)
           ++mp[nums[i]];
        int res = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
           if ((k && mp.find(it->first+k) != mp.end()) || (!k && it->second > 1))
               ++res;
        return res;
    }
};