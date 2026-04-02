class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_set<int> sSet(s.begin(), s.end());

        int res = 0;
        for (const char val : sSet) {
            int l = 0;
            int matches = 0;
            for (int r = 0; r < s.size(); ++r) {
                if (s[r] == val) ++matches;

                while ((r - l + 1) - matches > k) { // window invalid
                    if (s[l] == val) --matches;
                    ++l;
                }
                res = std::max(res, r - l + 1);
            }
        }
        return res;
    }
};
