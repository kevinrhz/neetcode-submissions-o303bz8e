class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) break; // if anchor isn't negative then solution is impossible. break early
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates from anchor

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    ++j;
                } else if (sum > 0) {
                    --k;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j; --k;
                    while (j < k && nums[j] == nums[j - 1]) ++j; // skip duplicates from two pointers
                }
            }
        }
        return res;
    }
};
