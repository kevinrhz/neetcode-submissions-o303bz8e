class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int res = 0;
        int target = threshold * k; // avoid division every iteration doing this instead of (sum / k >= threshold)
        for (int l = 0; l <= n - k; ++l) {
            int sum = 0;
            for (int r = l; r < l + k; ++r) {
                sum += arr[r];
            }
            if (sum >= target) { ++res; }
        }
        return res;
    }
};