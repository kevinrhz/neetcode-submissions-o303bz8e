class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() == 2) return {1, 2}; // only because every input has an answer, else this is dangerous

        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int curSum = numbers[i] + numbers[j];
            if (curSum > target) {
                --j;
                continue;
            } else if (curSum < target) {
                ++i;
                continue;
            } else {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};
