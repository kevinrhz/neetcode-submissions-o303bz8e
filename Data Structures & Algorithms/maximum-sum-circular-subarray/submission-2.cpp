class Solution {
public:
    int maxSubarraySumCircular(const vector<int>& nums) {
        int globMax = nums[0], globMin = nums[0];
        int curMax = 0, curMin = 0, total = 0;

        for (const int num : nums) {
            curMax = std::max(num, curMax + num);
            curMin = std::min(num, curMin + num);
            total += num;
            globMax = std::max(globMax, curMax);
            globMin = std::min(globMin, curMin);
        }
        return globMax > 0 ? std::max(globMax, total - globMin) : globMax;
    }
};