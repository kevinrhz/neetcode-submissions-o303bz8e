class Solution {
public:
    // 1. Const reference to prevent heap copies and guarantee read-only state
    int search(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            // 2. Binary Search midpoint with Bitwise Shift and Overflow prevention
            int m = l + ((r - l) >> 1);
            
            if (nums[m] == target) return m;

            // 3. Identify which half is "Sorted"
            // In a rotated array, at least one half (left or right) MUST be perfectly sorted.
            if (nums[l] <= nums[m]) {
                // Left half is sorted
                // 4. Check if target is within the boundaries of this sorted left half
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1; // Target is in the sorted left half
                } else {
                    l = m + 1; // Target must be in the "broken" right half
                }
            } else {
                // Right half is sorted
                // 5. Check if target is within the boundaries of this sorted right half
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1; // Target is in the sorted right half
                } else {
                    r = m - 1; // Target must be in the "broken" left half
                }
            }
        }
        return -1;
    }
};