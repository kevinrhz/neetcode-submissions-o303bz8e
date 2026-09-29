class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stk;
        for (const char p : s) {
            switch (p) {
                case '(': 
                case '{': 
                case '[':
                    stk.push_back(p); break;

                case ']':
                    if (stk.empty() || stk.back() != '[') { return false; }
                    stk.pop_back(); break;
                case '}':
                    if (stk.empty() || stk.back() != '{') { return false; }
                    stk.pop_back(); break;
                case ')':
                    if (stk.empty() || stk.back() != '(') { return false; }
                    stk.pop_back(); break;
            }
        }
        return stk.empty();
    }
};
