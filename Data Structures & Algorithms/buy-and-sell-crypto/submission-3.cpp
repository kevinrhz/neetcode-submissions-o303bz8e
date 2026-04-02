class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        size_t l = 0, r = l + 1;
        int resProfit = 0;

        while (r < prices.size()) {
            if (prices[r] <= prices[l]) {
                l = r;
            } else {
                int curProfit = prices[r] - prices[l];
                resProfit = std::max(curProfit, resProfit);
            }
            ++r;
        }
        return resProfit;
    }
};
