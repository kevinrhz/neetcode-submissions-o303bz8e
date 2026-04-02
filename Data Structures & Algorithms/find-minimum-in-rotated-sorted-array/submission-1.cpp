class Solution {
public:
    int findMin(const vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;

            // Is the right half perfectly sorted?
            if (nums[m] < nums[r]) {
                // Yes. The minimum is either exactly at 'm' or somewhere to its left.
                // We pull the right wall to 'm'. (Never m-1, or we might throw away the answer!)
                r = m;
            } else {
                // No. The right half is broken, which means the pivot/minimum MUST be over there.
                // Since 'm' is larger than the right wall, 'm' cannot be the minimum.
                l = m + 1;
            }
        }
        // The loop only breaks when l == r. They are pointing to the exact same, smallest number.
        return nums[l];
    }
};
