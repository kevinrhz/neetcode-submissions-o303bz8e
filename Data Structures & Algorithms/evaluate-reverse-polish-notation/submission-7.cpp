class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        std::vector<int> stk;
        stk.reserve(tokens.size());

        for (const std::string& token : tokens) {
            // Check if first char is a digit, or if len > 1 in case token[0] is negative sign.
            if (std::isdigit(token[0]) || token.size() > 1) {
                stk.push_back(std::stoi(token));
            } else {
                // Pop b then a to keep correct order for non-commutative operations (a - b, a / b).
                int b = stk.back(); stk.pop_back();
                int a = stk.back(); stk.pop_back();

                // Convert std::string token to char token[0], cause switch table can only process/optimize primitives.
                switch(token[0]) {
                    case '+':
                        stk.push_back(a + b);
                        break;
                    case '-':
                        stk.push_back(a - b);
                        break;
                    case '*':
                        stk.push_back(a * b);
                        break;
                    case '/':
                        stk.push_back(a / b);
                        break;
                }
            }
        }

        return stk.back();
    }
};
