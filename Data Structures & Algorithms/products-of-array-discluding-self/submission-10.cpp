class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        std::vector<int> prefix(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        } // [1, 1, 2, 8]

        std::vector<int> res(nums.size(), 1);
        int suffix_tracker = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = prefix[i] * suffix_tracker;
            suffix_tracker *= nums[i];
        }
        return res;
    }
};
