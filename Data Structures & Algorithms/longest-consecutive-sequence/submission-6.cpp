class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (const int num : numSet) {
            int len = 0;
            if (numSet.find(num - 1) == numSet.end()) { // if num is start of sequence
                while (numSet.find(num + len) != numSet.end()){
                    ++len;
                }
            }
            longest = std::max(longest, len);
        }
        return longest;
    }
};
