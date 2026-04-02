class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> charSet;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); ++r) {
            while (charSet.find(s[r]) != charSet.end()) { // increment l until no duplicates
                charSet.erase(s[l]);
                ++l;
            }
            charSet.insert(s[r]);
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};
