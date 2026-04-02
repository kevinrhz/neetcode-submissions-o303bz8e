class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *std::max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int totalTime = 0;
            long long k = l + (r - l) / 2;

            for (const int p : piles) {
                totalTime += (p + k - 1) / k;
            }

            if (totalTime <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
