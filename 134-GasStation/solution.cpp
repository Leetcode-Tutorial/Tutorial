class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int res = 0;     // 起始位置
        int remain = 0; // 当前剩余燃料
        int debt = 0;   // 之前没走完还差的燃料

        for (int i = 0; i < gas.size(); i++) {
            remain += gas[i] - cost[i];
            if (remain < 0) {
                debt += remain;
                remain = 0;
                res = i + 1;
            }
        }

      return remain + debt >= 0 ? res : -1;
    }
};