class Solution {
	public:
    bool canJump(vector<int>& nums) {
        int now = 0;
        for (int reach = 0; now < nums.size() && now <= reach; now++) {
        	reach = max(reach, now + nums[now]);
        }
        return now == nums.size();
    }
};