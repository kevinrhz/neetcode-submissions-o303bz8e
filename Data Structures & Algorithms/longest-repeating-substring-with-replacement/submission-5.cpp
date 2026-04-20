class Solution {
public:
    int characterReplacement(string& s, int k) {
        std::unordered_set<char> charSet(s.begin(), s.end());
        int res = 0;

        for (char c : charSet) {
            int count = 0;

            int l = 0;
            for (int r = 0; r < s.size(); ++r) {
                if (s[r] == c) {
                    ++count;
                }
                
                while ((r - l + 1) - count > k) {
                    if (s[l] == c) --count;
                    ++l;
                }
                res = std::max(res, r - l + 1);
            }
        }
        return res;
    }
};
