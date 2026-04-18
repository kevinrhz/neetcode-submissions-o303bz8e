class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;

        int maxP = 0;
        int buy = 0;
        for (int sell = 1; sell < n; ++sell) {
            if (prices[buy] < prices[sell]) {
                maxP = std::max(maxP, prices[sell] - prices[buy]);
            } else {
                buy = sell;
            }
        }
        return maxP;
    }
};
