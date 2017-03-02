class NumArray {
public:
    NumArray(vector<int> nums) {
        // nums may be empty
        if(nums.empty()) {
            return;
        }
        sums.push_back(nums[0]);
        int len = nums.size();
        for(int i = 1; i < len; i ++) {
            sums.push_back(sums[i-1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) {
            return sums[j];
        } else {
            return sums[j] - sums[i-1];
        }
    }

private:
    // record the sum of nums[0,i] into sums[i]
    vector<int>sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj(nums);
 * int param_1 = obj.sumRange(i,j);
 */
