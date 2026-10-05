class Solution {
public:
    int maxTurbulenceSize(const vector<int>& arr) {
        int l = 0, r = 1, res = 1;
        int prev = -1; // BOOL 0 is ">" and 1 is "<" and -1 is NULL

        while (r < arr.size()) {
            if (arr[r - 1] > arr[r] && prev != 0) {
                res = std::max(res, r - l + 1);
                ++r;
                prev = 0;
            } else if (arr[r - 1] < arr[r] && prev != 1) {
                res = std::max(res, r - l + 1);
                ++r;
                prev = 1;
            } else {
                if (arr[r - 1] == arr[r]) {
                    l = r;
                    prev = -1;
                    ++r;
                } else {
                    l = r - 1;
                    prev = -1;
                }
            }
        }
        return res;
    }
};