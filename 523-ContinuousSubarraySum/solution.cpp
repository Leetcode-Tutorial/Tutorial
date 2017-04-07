class Solution {
    public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> modSum;
        modSum[0]=-1;
        int prefixModSum=0;
        for(int i=0; i<nums.size(); i++){
            prefixModSum += nums[i];
            if(k!=0) prefixModSum %= k;
            auto getModSum = modSum.find(prefixModSum);
            if(getModSum != modSum.end()){
                if(i-getModSum->second > 1) return true;
            }else{
                modSum[prefixModSum]=i;
            }
        }
        return false;
    }
};
