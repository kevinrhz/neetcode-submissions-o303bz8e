class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int maxProfit = 0;

        int buy = 0;
        for (int sell = 0; sell < prices.size(); ++sell) {
            int profit = prices[sell] - prices[buy];
            maxProfit = std::max(maxProfit, profit);

            if (prices[buy] >= prices[sell]) buy = sell;
        }
        return maxProfit;
    }
};
