class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        int maxProfit = 0;
        int buy = 0;
        for (int sell = 1; sell < n; ++sell) {
            if (prices[buy] < prices[sell]) {
                maxProfit = std::max(maxProfit, prices[sell] - prices[buy]);
            } else {
                buy = sell;
            }
        }
        return maxProfit;
    }
};
