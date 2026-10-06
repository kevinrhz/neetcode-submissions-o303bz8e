class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            int k = 1;
            while (r + 1 < nums.size() && nums[r] == nums[r + 1]) {
                ++r; ++k;
            }

            for (int i = 0; i < std::min(k, 2); ++i) {
                nums[l] = nums[r];
                ++l;
            }
            ++r;
        }
        return l;
    }
};