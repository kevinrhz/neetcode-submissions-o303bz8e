class Solution {
public:
    int maxArea(const vector<int>& heights) {
        int res = 0;

        int i = 0, j = heights.size() - 1;
        while (i < j) {
            res = std::max(res, (j - i) * std::min(heights[i], heights[j]));

            if (heights[i] < heights[j]) { ++i; }
            else                         { --j; }
        }
        return res;
    }
};
