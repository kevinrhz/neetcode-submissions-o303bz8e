const static int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        std::vector<int> stack;
        stack.reserve(tokens.size());

        for (const std::string& token : tokens) {
            if (token.size() > 1 || std::isdigit(token[0])) {
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
