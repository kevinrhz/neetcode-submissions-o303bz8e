class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0; // result

        for (const int num : numSet) {
            int len = 0;
            if (numSet.find(num - 1) != numSet.end()) continue;
            while(numSet.find(num + len) != numSet.end()) ++len;
            longest = std::max(longest, len);
        }
        return longest;
    }
};
