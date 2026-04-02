class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // [1, 2, 4, 6]
        std::vector<int> pref(n);
        std::vector<int> suff(n);
        std::vector<int> res(n);

        // set boundaries to avoid edge cases. prefix product uses 1 and prefix sum uses 0
        pref[0] = 1;
        suff[n - 1] = 1;

        // build prefix product array
        for (size_t i = 1; i < n; ++i) {
            pref[i] = nums[i - 1] * pref[i - 1];
        } // [1, 1, 2, 8]

        // build suffix product array
        for (int i = n - 2; i >= 0; --i) {
            suff[i] = nums[i + 1] * suff[i + 1];
        } // [48, 24, 6, 1]

        // build the result
        for (size_t i = 0; i < n; ++i) {
            res[i] = pref[i] * suff[i];
        } // [48, 26, 12, 8]
        return res;
    }
};
