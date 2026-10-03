class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int maxSum = nums[0], curSum = 0;
        for (const int num : nums) {
            if (curSum < 0) { curSum = 0; }
            curSum += num;
            maxSum = std::max(maxSum, curSum);
        }
        return maxSum;
    }
};
