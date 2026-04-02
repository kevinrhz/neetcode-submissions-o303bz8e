class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::vector<int> count(26, 0);
        for (size_t i = 0; i < s.size(); ++i) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }
        for (const auto& x : count) {
            if (x != 0) return false;
        }
        return true;
    }
};
