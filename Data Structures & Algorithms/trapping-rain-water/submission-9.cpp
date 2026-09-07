class Solution {
public:
    int trap(const vector<int>& height) {
        if (height.size() < 2) return 0;
        int res = 0;

        int maxL = 0, maxR = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int currL = height[l];
            int currR = height[r];
            maxL = std::max(maxL, currL);
            maxR = std::max(maxR, currR);

            if (currL < maxL && currL < maxR) {
                res += std::min(maxL, maxR) - currL;
            } else if (currR < maxL && currR < maxR) {
                res += std::min(maxL, maxR) - currR;
            }

            if (currL > currR) { --r; }
            else               { ++l; }
        }
        return res;
    }
};
