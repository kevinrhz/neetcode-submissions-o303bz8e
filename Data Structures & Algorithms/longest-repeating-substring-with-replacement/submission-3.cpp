static const int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int characterReplacement(const string& s, int k) {
        int count[26] = {0};

        int l = 0;
        int max_freq = 0;
        int res = 0;
        for (int r = 0; r < s.size(); ++r) {
            int right_char = s[r] - 'A';
            ++count[right_char];

            max_freq = std::max(max_freq, count[right_char]);

            if ((r - l + 1) - max_freq > k) {
                --count[s[l] - 'A'];
                ++l;
            }
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};
