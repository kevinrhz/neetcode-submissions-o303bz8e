class Solution {
public:
    int maxArea(vector<int>& heights) {
        if (heights.size() == 2) return (std::min(heights[0], heights[1]));

        int resArea = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int curArea = std::min(heights[l], heights[r]) * (r - l);
            if (heights[l] < heights[r]) {
                ++l;
            } else {
                --r;
            }

            resArea = std::max(curArea, resArea);
        }
        return resArea;
    }
};
