class Solution {
public:
    int findMaxConsecutiveOnes(const vector<int>& nums) {
        int res = 0;
        int count = 0;
        for (const int n : nums) {
            if (n == 1) {
                ++count;
                res = std::max(res, count);
            } else {
                count = 0;
            }
        }
        return res;
    }
};