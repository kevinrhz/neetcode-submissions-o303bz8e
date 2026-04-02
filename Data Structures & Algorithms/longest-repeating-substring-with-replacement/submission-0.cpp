class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        std::unordered_set<char> charSet(s.begin(), s.end());

        for (const char c : charSet) { // find longest valid window for each unique character
            int l = 0, count = 0;
            for (int r = 0; r < s.size(); ++r) { // grow/SLIDE window to right
                if (s[r] == c) ++count; // if the right positions value is the char we are currently evaluating from set, INCREMENT COUNT

                while ((r - l + 1) - count > k) { // while window is invalid ((window_size - charCount) > k)
                    if (s[l] == c) --count; // if the char we are removing is the char we are currently evaluating from set, DECREMENT COUNT
                    ++l; // SLIDE window to right
                }

                res = std::max(res, r - l + 1); // update res with size of current window
            }
        }
        return res;
    }
};
