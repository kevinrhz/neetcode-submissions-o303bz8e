class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (const int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) { // if num is start of sequence, no (num - 1) in set
                int len = 1;
                while (numSet.find(num + len) != numSet.end()) { // while the consecutive num is also in set
                    ++len;
                }
                longest = std::max(longest, len);
            }
        }
        return longest;
    }
};
