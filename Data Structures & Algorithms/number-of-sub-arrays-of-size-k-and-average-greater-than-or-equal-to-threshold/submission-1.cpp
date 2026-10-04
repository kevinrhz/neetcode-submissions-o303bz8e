class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0, curSum = 0;
        threshold *= k; // in-place calculate target to avoid per iteration division

        for (int i = 0; i < arr.size(); ++i) {
            curSum += arr[i];
            if (i >= k - 1) { // if valid window
                if (curSum >= threshold) { ++res; } // update res
                curSum -= arr[i - k + 1]; // shrink window from left
            }
        }
        return res;
    }
};