class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> countS;
        std::unordered_map<char, int> countT;

        for (size_t i = 0; i < s.size(); ++i) {
            ++countS[s[i]];
            ++countT[t[i]];
        }
        return countS == countT;
    }
};
