class NumArray {
public:
    NumArray(vector<int> nums) {
        arr = nums;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for(int k = i; k <= j; k ++) {
            sum += arr[k];
        }
        return sum;
    }
private:
    //transfer the nums
    vector<int> arr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
