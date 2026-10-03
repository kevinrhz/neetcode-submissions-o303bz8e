class Solution {
public:
    int maxSubarraySumCircular(const vector<int>& nums) {
        int globMax = nums[0], globMin = nums[0];
        int curMax = 0, curMin = 0, total = 0;

        for (const int num : nums) {
            curMax = std::max(curMax + num, num);
            curMin = std::min(curMin + num, num);
            total += num;
            globMax = std::max(globMax, curMax);
            globMin = std::min(globMin, curMin);
        }
        // Returning globMax is a middle subarray, and total - globMin is a wraparound array.
        // Ensure at least one positive number in array by checking globMax is positive at end. To avoid total - globMin being 0 which is invalid.
        return globMax > 0 ? std::max(globMax, total - globMin) : globMax;
    }
};