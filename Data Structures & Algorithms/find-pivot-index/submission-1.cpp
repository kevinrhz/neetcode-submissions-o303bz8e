#include <numeric>

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int preSum = 0, total = std::accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            int postSum = total - nums[i] - preSum;
            if (preSum == postSum) {
                return i;
            }
            preSum += nums[i];
        }
        return -1;
    }
};