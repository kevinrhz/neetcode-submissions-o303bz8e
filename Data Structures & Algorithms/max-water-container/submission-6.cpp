class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;

        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int len = r - l;
            int area = std::min(heights[l], heights[r]) * len;
            if (heights[l] < heights[r]) {
                ++l;
            } else {
                --r;
            }
            res = std::max(res, area);
        }
        return res;
    }
};
