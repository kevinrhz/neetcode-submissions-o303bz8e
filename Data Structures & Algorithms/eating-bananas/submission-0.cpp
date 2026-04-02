class Solution {
public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        // 1. Find the max element for our upper bound
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int k = l + (r - l) / 2; // binary search mid
            
            long long totalTime = 0;
            for (int p : piles) {
                // 2. Pure integer ceiling division! No double, no ceil()
                totalTime += (p + k - 1) / k; 
            }

            if (totalTime <= h) {
                res = k;
                r = k - 1; // Try to find a smaller valid speed
            } else {
                l = k + 1; // Speed was too slow
            }
        }
        
        return res;
    }
};