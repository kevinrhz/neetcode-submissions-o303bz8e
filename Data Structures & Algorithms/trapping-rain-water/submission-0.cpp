class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int n = height.size();
        int res = 0;

        for (int i = 0; i < n; ++i) {
            int leftMax = height[i];
            int rightMax = height[i];

            for (int j = 0; j < i; ++j) {
                leftMax = std::max(leftMax, height[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                rightMax = std::max(rightMax, height[j]);
            }

            res += std::min(leftMax, rightMax) - height[i];
        }
        return res;
    }
};
