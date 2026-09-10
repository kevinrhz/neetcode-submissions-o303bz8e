class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        int maxProfit = 0, lowestPrice = prices[0];
        int buy = 0;
        for (int sell = 1; sell < n; ++sell) {
            lowestPrice = std::min(lowestPrice, prices[buy]);
            int profit = prices[sell] - lowestPrice;
            maxProfit = std::max(maxProfit, profit);
            ++buy;
        }
        return maxProfit;
    }
};
