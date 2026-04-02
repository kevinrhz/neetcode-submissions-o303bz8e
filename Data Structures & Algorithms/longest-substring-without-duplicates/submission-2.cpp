class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> charSet;
        int longest = 0;
        int l = 0;

        for (int r = 0; r < s.size(); ++r) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                ++l;
            }
            charSet.insert(s[r]);
            longest = std::max(longest, r - l + 1);
        }
        return longest;
    }
};
