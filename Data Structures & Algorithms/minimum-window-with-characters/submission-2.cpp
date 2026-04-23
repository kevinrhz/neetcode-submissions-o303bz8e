class Solution {
   public:
    string minWindow(string s, string t) {
        int minWindowStart = 0;
        int minWindowLen = -1;

        int tCount[128] = {0};
        for (char c : t) { ++tCount[c]; }

        int windowCount[128] = {0};
        int have = 0, need = t.size();
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            ++windowCount[c];

            if (tCount[c] > 0 && windowCount[c] <= tCount[c]) {
                ++have;
            }

            while (have == need) {
                int curLen = r - l + 1;
                if (minWindowLen == -1 || curLen < minWindowLen) { // if current window length is less than minWindowLen, update it
                    minWindowStart = l;
                    minWindowLen = curLen;
                }

                char leftChar = s[l];
                --windowCount[leftChar];

                if (tCount[leftChar] > 0 && windowCount[leftChar] < tCount[leftChar]) {
                    --have;
                }

                ++l;
            }
        }
        return minWindowLen == -1 ? "" : s.substr(minWindowStart, minWindowLen);
    }
};
