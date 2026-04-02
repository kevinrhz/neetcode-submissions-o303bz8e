class Solution {
public:
    bool isValid(const string& s) {
        if (s.size() % 2 == 1) return false;

        std::vector<char> stack;
        stack.reserve(s.size());
        
        for (const char c : s) {
            switch(c) {
                case '{':
                case '(':
                case '[':
                    stack.push_back(c);
                    break;
                case '}':
                    if (stack.back() != '{') return false;
                    stack.pop_back();
                    break;
                case ')':
                    if (stack.back() != '(') return false;
                    stack.pop_back();
                    break;
                case ']':
                    if (stack.back() != '[') return false;
                    stack.pop_back();
                    break;
            }
        }
        return stack.empty();
    }
};
