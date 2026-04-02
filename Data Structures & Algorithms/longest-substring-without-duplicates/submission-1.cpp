class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> mp;
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); ++r) {
            if (mp.find(s[r]) != mp.end()) {
                l = std::max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};
