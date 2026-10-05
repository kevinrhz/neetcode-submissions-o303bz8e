class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        std::unordered_set<char> seen;
        int res = 0, l = 0;

        for (int r = l; r < s.size(); ++r) {
            while (seen.count(s[r])) {
                seen.erase(s[l]);
                ++l;
            }
            seen.insert(s[r]);
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};
