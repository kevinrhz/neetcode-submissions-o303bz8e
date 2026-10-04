class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = nums.size() + 1;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum >= target) {
                    length = std::min(length, j - i + 1);
                }
            }
        }
        return length == nums.size() + 1 ? 0 : length;
    }
};