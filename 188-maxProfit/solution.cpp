class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int dp[100005]; //前i天进行了j次交易的最大收益
        int n = prices.size (); 
        k <<= 1;
        
        for (int i = 0; i < 100005; i++) dp[i] = -1e9;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int val = prices[i-1];
            for (int j = i; j >= 0; j--) {
                if (!j) continue; //这一天不做交易
                if (j&1) { //这一天买入股票
                    dp[j] = max (dp[j], dp[j-1]-val); 
                }
                else { //这一天卖出股票
                    dp[j] = max (dp[j], dp[j-1]+val);
                }
            }
        }
        int ans = -1e9;
        for (int i = 0; i <= min (n, k); i += 2) ans = max (ans, dp[i]);
        return ans;
    }
};
