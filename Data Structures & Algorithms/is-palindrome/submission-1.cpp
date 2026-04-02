class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 1 && std::isalnum(s[0])) return true;

        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (!std::isalnum(s[l])) {
                ++l;
                continue;
            }
            if (!std::isalnum(s[r])) {
                --r;
                continue;
            }
            if (std::tolower(s[l]) != std::tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};
