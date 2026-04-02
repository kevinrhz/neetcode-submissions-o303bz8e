class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            int area = std::min(heights[l], heights[r]) * (r - l);
            res = std::max(res, area);

            if (heights[l] <= heights[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};
