class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0], maxP = 0;

        for (int& sell : prices) {
            maxP = std::max(maxP, sell - minBuy);
            minBuy = std::min(minBuy, sell);
        }
        return maxP;
    }
};
