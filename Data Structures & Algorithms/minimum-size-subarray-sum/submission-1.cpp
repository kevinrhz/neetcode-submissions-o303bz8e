class Solution {
public:
    int minSubArrayLen(int target, const vector<int>& nums) {
        const int n = nums.size();
        int l = 0, sum = 0, length = n + 1;

        for (int r = l; r < n; ++r) {
            sum += nums[r];
            while (sum >= target) {
                length = std::min(length, r - l + 1);
                sum -= nums[l];
                ++l;
            }
        }
        return length == n + 1 ? 0 : length;
    }
};