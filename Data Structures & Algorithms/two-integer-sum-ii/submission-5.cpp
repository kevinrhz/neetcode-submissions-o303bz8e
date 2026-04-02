class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        size_t l = 0;
        size_t r = numbers.size() - 1;

        while (l < r) {
            int curSum = numbers[l] + numbers[r];

            if (curSum > target) {
                --r;
            } else if (curSum < target) {
                ++l;
            } else {
                return {l + 1, r + 1};
            }
        }
        return {};
    }
};
