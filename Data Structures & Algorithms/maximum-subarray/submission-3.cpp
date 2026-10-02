class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = 0;

        for (const int num : nums) {
            curSum = std::max(curSum, 0);
            curSum += num;
            maxSum = std::max(maxSum, curSum);
        }
        return maxSum;
    }
};
