class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int count[26] = {0};
        int matches = 0;

        for (int i = 0; i < s1.size(); ++i) {
            ++count[s1[i] - 'a'];
            --count[s2[i] - 'a'];
        }
        for (const int num : count) {
            if (num == 0) ++matches;
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
