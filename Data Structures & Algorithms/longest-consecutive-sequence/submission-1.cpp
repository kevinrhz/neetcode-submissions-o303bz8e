class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numsSet(nums.begin(), nums.end());
        int res = 0;

        for (const int n : nums) {
            int streak = 0;
            int curr = n;

            while (numsSet.find(curr) != numsSet.end()) {
                ++streak;
                ++curr;
            }
            res = std::max(res, streak);
        }
        return res;
    }
};
