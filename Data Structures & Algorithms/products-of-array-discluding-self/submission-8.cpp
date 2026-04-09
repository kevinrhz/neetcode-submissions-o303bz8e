class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> pref(n);
        std::vector<int> suff(n);
        std::vector<int> res(n);

        pref[0] = 1;
        for (int i = 1; i < n; ++i) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }

        suff[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            suff[i] = nums[i + 1] * suff[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};
