class Solution {
public:
    int numOfSubarrays(const vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int res = 0, sum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            // Manage window size with ++sum-- rather than pointers
            sum += arr[i];
            if (i >= k - 1) { // Has window reached size k yet in the first place? Then start evaluating, all further window sizes handled by sum.
                if (sum >= threshold) { ++res; }
                sum -= arr[i - k + 1];
            }
        }
        return res;
    }
};