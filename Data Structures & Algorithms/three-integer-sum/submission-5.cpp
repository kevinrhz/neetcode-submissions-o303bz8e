class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res; // [[i1, j1, k1], [i2, j2, k2], ... [in, jn, kn]]

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int curSum = nums[i] + nums[j] + nums[k];
                if (curSum < 0) {
                    ++j;
                } else if (curSum > 0) {
                    --k;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                }
            }
        }
        return res;
    }
};
