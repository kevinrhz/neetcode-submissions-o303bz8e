class Solution {
public:
    int findMin(const vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int res = 0;

        if (nums[l] < nums[r]) return nums[l];

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};
