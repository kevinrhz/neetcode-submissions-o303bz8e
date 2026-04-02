class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) return false;

        std::vector<char> stack;
        stack.reserve(n);

        for (const char c : s) {
            switch(c) {
                case '{':
                case '(':
                case '[':
                    stack.push_back(c);
                    break;
                case '}':
                    if (stack.empty() || '{' != stack.back()) return false;
                    stack.pop_back();
                    break;
                case ')':
                    if (stack.empty() || '(' != stack.back()) return false;
                    stack.pop_back();
                    break;
                case ']':
                    if (stack.empty() || '[' != stack.back()) return false;
                    stack.pop_back();
                    break;
            }
        }
        return stack.empty();
    }
};
