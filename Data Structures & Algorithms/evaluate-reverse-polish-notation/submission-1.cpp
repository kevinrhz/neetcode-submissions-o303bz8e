class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        std::vector<int> stack(tokens.size() / 2 + 1);
        int res = 0;
        
        for (const auto& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                stack.push_back(std::stoi(token));
                continue;
            }

            int b = stack.back(); stack.pop_back();
            int a = stack.back(); stack.pop_back();

            switch(token[0]) {
                case '+':
                    stack.push_back(a + b);
                    break;
                case '-':
                    stack.push_back(a - b);
                    break;
                case '*':
                    stack.push_back(a * b);
                    break;
                case '/':
                    stack.push_back(a / b);
                    break;
            }
        }
        return stack.back();
    }
};
