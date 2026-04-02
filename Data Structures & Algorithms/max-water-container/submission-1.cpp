class Solution {
public:
    int maxArea(vector<int>& heights) {
        size_t l = 0, r = heights.size() - 1;
        int resArea = 0;

        while (l < r) {
            int curArea = std::min(heights[l], heights[r]) * (r - l);
            resArea = max(resArea, curArea);

            if (heights[l] <= heights[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return resArea;
    }
};
