class Solution {
public:
    // 1. Pass by const reference to guarantee read-only memory access
    int findMin(const vector<int>& nums) {
        int res = nums[0];
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            // 2. Early Exit: If the current window is already perfectly sorted, 
            // the leftmost element is guaranteed to be the absolute minimum.
            if (nums[l] < nums[r]) {
                res = std::min(res, nums[l]);
                break;
            }
            
            // 3. Calculate midpoint and save to res if smaller.
            int m = l + (r - l) / 2;
            res = std::min(res, nums[m]);

            // 4. If the left half is sorted, the pivot/minimum MUST be in the right half.
            if (nums[m] >= nums[l]) {
                l = m + 1; 
            } else {
                // Otherwise, the right half is sorted, so the minimum is in the left half.
                r = m - 1; 
            }
        }
        return res;
    }
};