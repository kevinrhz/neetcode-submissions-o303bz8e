const static int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int count[26] = {0};
        for (int i = 0; i < s1.size(); ++i) {
            ++count[s1[i] - 'a'];
            --count[s2[i] - 'a'];
        }
        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) ++matches;
        }

        int l = 0;
        for (int r = s1.size(); r < s2.size(); ++r) {
            if (matches == 26) return true;

            int index = s2[r] - 'a';
            --count[index];
            if (count[index] == 0) ++matches;
            else if (count[index] == -1) --matches;

            index = s2[l] - 'a';
            ++count[index];
            if (count[index] == 0) ++matches;
            else if (count[index] == 1) --matches;

            ++l;
        }
        return matches == 26;
    }
};
