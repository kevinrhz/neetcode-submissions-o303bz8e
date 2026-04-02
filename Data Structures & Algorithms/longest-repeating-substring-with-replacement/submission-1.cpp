class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        std::unordered_set<char> charSet(s.begin(), s.end());

        for (const char c : s) {
            int l = 0, count = 0;
            for (int r = 0; r < s.size(); ++r) {
                if (s[r] == c) ++count;
                while ((r - l + 1 - count) > k) { // window is invalid
                    if (s[l] == c) --count;
                    ++l;
                }
                res = std::max(res, r - l + 1);
            }
        }
        return res;
    }
};
