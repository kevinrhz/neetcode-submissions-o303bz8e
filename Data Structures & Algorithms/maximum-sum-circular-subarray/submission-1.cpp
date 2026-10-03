class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], n = nums.size();
        for (int i = 0; i < n; ++i) {
            int curSum = 0;
            for (int j = i; j < i + n; ++j) {
                curSum += nums[j % n];
                maxSum = std::max(maxSum, curSum);
            }
        }
        return maxSum;
    }
};