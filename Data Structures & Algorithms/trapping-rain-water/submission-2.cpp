class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int l = 0, r = n - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;

        while (l < r) {
            if (leftMax < rightMax) {
                ++l;
                leftMax = std::max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                --r;
                rightMax = std::max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
