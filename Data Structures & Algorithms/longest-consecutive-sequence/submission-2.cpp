class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::sort(nums.begin(), nums.end());

        int res = 0;
        int curr = nums[0];
        int streak = 0;
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] != curr) {
                curr = nums[i];
                streak = 0;
            }
            while (i < nums.size() && nums[i] == curr) {
                ++i;
            }
            ++streak;
            ++curr;
            res = std::max(res, streak);
        }
        return res;
    }
};
