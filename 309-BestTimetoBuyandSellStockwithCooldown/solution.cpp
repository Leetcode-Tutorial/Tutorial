class Solution {
	public:
	    int maxProfit(vector<int> &prices) {
		    int buy = -0x3f3f3f3f, sell = 0, prev_sell = 0, prev_buy;
		    for (int i = 0; i < (int)prices.size(); i++) {
		        int price = prices[i];
		        prev_buy = buy;
		        buy = max(prev_sell - price, buy);
		        prev_sell = sell;
		        sell = max(prev_buy + price, sell);
	    }
	    return sell;
	}
};