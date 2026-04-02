class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;

        std::unordered_set<int> seen;
        int longest = 0;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            while (seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                ++l;
            }
            int len = r - l + 1;
            seen.insert(s[r]);
            longest = std::max(longest, len);
        }
        return longest;
    }
};
