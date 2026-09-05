class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        const int n = nums.size();
        std::vector<std::vector<int>> res;
        res.reserve(n);
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) { break; }

            int j = i + 1, k = n - 1;
            if (i > 0 && nums[i] == nums[i - 1]) { continue; }

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) { ++j; }
                else if (sum > 0) { --k; }
                else {
                    while (j < k && nums[j] == nums[j + 1]) { ++j; }
                    while (j < k && nums[k] == nums[k - 1]) { --k; }
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j; --k;
                }
            }

        }
        return res;
    }
};