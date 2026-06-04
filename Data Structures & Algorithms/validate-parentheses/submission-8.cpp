class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stack;
        
        for (const char c : s) {
            switch(c) {
                case '{':
                case '[':
                case '(':
                    stack.push_back(c);
                    break;
                    
                case '}':
                    if (stack.empty() || stack.back() != '{') return false;
                    stack.pop_back();
                    break;
                case ']':
                    if (stack.empty() || stack.back() != '[') return false;
                    stack.pop_back();
                    break;
                case ')':
                    if (stack.empty() || stack.back() != '(') return false;
                    stack.pop_back();
                    break;
            }
        }
        return stack.empty();
    }
};
