class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        int dp = 0;
        int min = prices[0];
        for(int i = 1; i < len; i++){
            dp = max(dp, prices[i]-min);
            if(prices[i] < min) min = prices[i];
        }
        return dp;
    }
};