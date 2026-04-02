class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) ++j;
                else if (sum > 0) --k;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j; --k;

                    // Skip duplicates for the 'j' pointer to avoid duplicate triplets
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                }
            }
        }
        return res;
    }
};
