class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0, i = 0;
        long long sum = 0;
        while(sum < n){
            if(i < nums.size()&&nums[i] <= sum+1)
                sum += nums[i++];
            else{
                ans++;
                sum += sum+1;
            }
        }
        return ans;
    }
};
