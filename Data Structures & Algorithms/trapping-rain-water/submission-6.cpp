class Solution {
public:
    int trap(vector<int>& height) {
        static const int _ = []() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            return 0;
        }();

        int n = height.size();
        if (n == 1) return 0;
        int res = 0;

        int* h = height.data();

        int l = 0, r = n - 1;
        int maxL = h[l], maxR = h[r];
        while (l < r) {
            if (h[l] < h[r]) {
                ++l;
                if (h[l] >= maxL) maxL = h[l];
                res += maxL - h[l];
            } else {
                --r;
                if (h[r] >= maxR) maxR = h[r];
                res += maxR - h[r];
            }
        }
        return res;
    }
};
