class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty()) return "";

        std::vector<int> countT(128, 0);
        int need = 0;
        for (const char c : t) {
            if (countT[c] == 0) ++need; // count unique characters needed
            ++countT[c];
        }

        std::vector<int> window(128, 0);
        int have = 0;

        int minLen = INT_MAX;
        int minStart = 0;

        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            ++window[c];

            if (countT[c] > 0 && window[c] == countT[c]) {
                ++have;
            }

            while (have == need) {
                // Update result logic: Clean and strictly inside the valid window check
                int currentWindowLen = r - l + 1;
                if (currentWindowLen < minLen) {
                    minLen = currentWindowLen;
                    minStart = l;
                }

                // Shrink window
                char leftChar = s[l];
                --window[leftChar];

                // If we drop below the needed count for a target character, we are no longer valid
                if (countT[leftChar] > 0 && window[leftChar] < countT[leftChar]) {
                    --have;
                }
                ++l;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
