class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;

        for (int i = 0; i < nums.size() - k + 1; ++i) {
            int l = i, r = i + k;
            int subMax = INT_MIN;
            for (int j = l; j < r; ++j) {
                subMax = std::max(subMax, nums[j]);
            }
            res.push_back(subMax);
        }
        return res;
    }
};
