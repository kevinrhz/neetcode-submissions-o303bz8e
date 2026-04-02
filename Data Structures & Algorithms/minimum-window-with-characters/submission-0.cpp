class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        std::unordered_map<char, int> countT, window;
        for (const char c : t) {
            ++countT[c];
        }

        int have = 0, need = countT.size();
        std::pair<int, int> res = {-1, -1}; // initialize pair to sentinels to indicate no valid windows by end since valid indices are alway non-negative.
        int resLen = INT_MAX; // set to largest int so any resulting length will strictly be smaller, acts as infinity for comparison purposes.
        int l = 0;

        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            ++window[c]; // update window with current char

            // is my current char in my T string? If yes, did I just reach the EXACT count needed for this character?
            if (countT.count(c) && window[c] == countT[c]) {
                ++have;
            }
            
            // while i have what i need, shrink the window until i no longer have what i need to find another possible substring
            while (have == need) {
                // first update my results
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                // then remove s[l] from the window. If this makes our window no longer satisfy the requirement for s[l], decrement 'have'.
                --window[s[l]];
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    --have;
                }
                ++l; // shrink window from the left
            }
        }
        // if result length is MAX return "" else return the valid answer found
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen); // remember substr takes (start, len) and not (start, end).
    }
};
