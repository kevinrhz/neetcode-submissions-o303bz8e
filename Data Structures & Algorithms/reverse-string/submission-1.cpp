class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
    }

private:
    void reverse(std::vector<char>& s, int l, int r) {
        if (l < r) {
            reverse(s, l + 1, r - 1);
            std::swap(s[l], s[r]);
        }
    }
};