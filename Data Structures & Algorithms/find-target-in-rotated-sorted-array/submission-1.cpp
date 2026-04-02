class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        // ---------------------------------------------------------
        // PASS 1: Find the Pivot (Index of the smallest element)
        // ---------------------------------------------------------
        // This is the exact "Boundary" template from the previous problem.
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1; // Right half is broken, pivot must be over there
            } else {
                r = m;     // Right half is sorted, pivot is at 'm' or to its left
            }
        }

        int pivot = l;
        
        // Reset pointers to the full array boundaries
        l = 0;
        r = nums.size() - 1;

        // ---------------------------------------------------------
        // THE BRIDGE: Choose which sorted half to search
        // ---------------------------------------------------------
        // The array from 'pivot' to the end 'r' is guaranteed to be perfectly sorted.
        // We check if our target falls neatly inside that right-side window.
        if (target >= nums[pivot] && target <= nums[r]) {
            l = pivot;     // Target is in the right sorted half
        } else {
            r = pivot - 1; // Target must be in the left sorted half
        }

        // ---------------------------------------------------------
        // PASS 2: Standard Exact-Match Binary Search
        // ---------------------------------------------------------
        // Now that l and r are locked into a perfectly sorted subarray, 
        // we just do a normal binary search.
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return -1;
    }
};