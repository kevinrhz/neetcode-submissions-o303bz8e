class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;

        for (int num : numSet) {
            if (numSet.count(num - 1) > 0) continue; // if num isnt start of a sequence continue

            int len = 1;
            while (numSet.find(num + len) != numSet.end()) {
                ++len;
            }

            res = std::max(res, len);
        }
        return res;
    }
};
