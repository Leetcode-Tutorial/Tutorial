class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        map<int,int>Map;
        int len1 = nums1.size(),len2 = nums2.size(),i;
        for(i = 0;i<len1;i++)
        {
            Map[nums1[i]]++;
        }
        for(i = 0;i<len2;i++)
        {
            if(Map[nums2[i]]>0)
            {
                res.push_back(nums2[i]);
                Map[nums2[i]] = 0;     //因为它不允许重复的，那么在这里就一定要清零
            }
        }
        return res;
    }
};