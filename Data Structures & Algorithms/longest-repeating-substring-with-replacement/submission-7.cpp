class Solution {
public:
    int characterReplacement(const string& s, int k) {
        std::unordered_set<char> evals(s.begin(), s.end());
        int res = 0;

        for (const char c : evals) {
            int l = 0, count = 0;
            for (int r = l; r < s.size(); ++r) {
                if (s[r] == c) {++count; }

                while ((r - l + 1) - count > k) {
                    if (s[l] == c) { --count; }
                    ++l;
                }
                res = std::max(res, r - l + 1);
            }
        }
        return res;
    }
};
