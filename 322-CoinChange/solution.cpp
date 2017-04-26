class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0; i<amount; i++){
            if(dp[i]==INT_MAX) continue;
            for(auto& num: coins){
                if(i+(long long)num>amount) break;
                dp[i+num] = min(dp[i]+1,dp[i+num]);
            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};
