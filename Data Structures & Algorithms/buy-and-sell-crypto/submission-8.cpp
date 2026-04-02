class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        int resProfit = 0;
        int buy = 0, sell = 1;
        while (sell < prices.size()) {
            if (prices[sell] <= prices[buy]) {
                buy = sell;
            }
            int curProfit = prices[sell] - prices[buy];
            resProfit = std::max(curProfit, resProfit);
            ++sell;
        }
        return resProfit;
    }
};
