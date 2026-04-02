class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::size_t l = 0;
        std::size_t r = numbers.size() - 1;

        while (l < r) {
            const long long curSum = static_cast<long long>(numbers[l] + numbers[r]);
            if (curSum > target) {
                --r;
            } else if (curSum < target) {
                ++l;
            } else {
                return {static_cast<int>(l + 1), static_cast<int>(r + 1)};
            }
        }
        return {};

    }
};
