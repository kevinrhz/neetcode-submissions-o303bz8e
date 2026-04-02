class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;

        if (nums.size() < 3) return res;

        // index value anchor loop
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            // edge cases
            if (nums[i] > 0) break;
            if (i > 0 && (nums[i] == nums[i - 1])) continue;

            // pointers declarations
            size_t l = i + 1;
            size_t r = nums.size() - 1;

            // two pointer loop
            while (l < r) {
                int curSum = nums[l] + nums[r] + nums[i];
                if (curSum > 0) {
                    --r;
                } else if (curSum < 0) {
                    ++l;
                } else {
                    res.emplace_back(std::vector<int>{nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    // drain duplicates for the pointers
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                }
            }
        }
        return res;
    }
};
