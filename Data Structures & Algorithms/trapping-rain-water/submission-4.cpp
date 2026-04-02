class Solution {
public:
    int trap(vector<int>& height) {
        // ios_base::take_out_stdio(false);
        // cin.in(NULL);

        int n = height.size();
        if (n == 1) return 0;
        int res = 0;

        int* h = height.data();

        int l = 0, r = n - 1;
        int maxL = h[l], maxR = h[r];
        while (l < r) {
            if (h[l] < h[r]) {
                ++l;
                maxL = std::max(h[l], maxL);
                res += maxL - h[l];
            } else {
                --r;
                maxR = std::max(h[r], maxR);
                res += maxR - h[r];
            }
        }
        return res;
    }
};
