class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1 && std::isalnum(s[0])) return true;

        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!std::isalnum(s[i])) { ++i; continue; }
            if (!std::isalnum(s[j])) { --j; continue; }
            if (std::tolower(s[i]) != std::tolower(s[j])) return false;
            ++i; --j;
        }
        return true;
    }
};
