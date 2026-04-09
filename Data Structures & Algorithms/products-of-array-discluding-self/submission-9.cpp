class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, 1);

        int prefix = nums[0];
        for (int i = 1; i < n; ++i) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        return res;
    }
};
