class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;

        if (nums.size() < 3) return res;
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            size_t l = i + 1;
            size_t r = nums.size() - 1;
            
            // drain duplicates for index
            if (i > 0 && (nums[i] == nums[i - 1])) continue;
            
            while (l < r) {
                int curSum = (nums[l] + nums[r]) + nums[i];
                if (curSum > 0) {
                    --r;
                } else if (curSum < 0) {
                    ++l;
                } else {
                    // res.emplace_back(std::vector<int>{nums[i], nums[l], nums[r]});
                    // use emplace_back for zero copy
                    res.push_back({nums[i], nums[r], nums[l]});
                    ++l;
                    --r;
                    // drain duplicates for the pointers
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        return res;
    }
};
