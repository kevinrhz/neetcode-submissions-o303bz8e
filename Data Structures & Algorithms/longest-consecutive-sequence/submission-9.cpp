class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_set<int> numSet(nums.begin(), nums.end());
        // I use an unordered_set to achieve O(n) as per problem constraints. But sorting original array for O(nlogn) would have better cache locality and likely perform better on hardware than this O(n) depending on constraints. Im curious if true.

        int longest = 0;
        for (int n : numSet) {
            int count = 1;
            if (numSet.count(n - 1) == 0) {
                while (numSet.count(n + count)) {
                    ++count;
                }
            }
            longest = std::max(longest, count);
        }
        return longest;
    }
};
