class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        std::vector<int> stk;

        for (const std::string& token : tokens) {
            // check if first char is a digit, or if len > 1 in case token[0] is negative sign
            if (std::isdigit(token[0]) || token.size() > 1) {
                stk.push_back(std::stoi(token));
            } else {
                // Pop b then a to keep correct order for non-commutative operations (a - b, a / b).
                int b = stk.back(); stk.pop_back();
                int a = stk.back(); stk.pop_back();

                if (token == "+") stk.push_back(a + b);
                else if (token == "-") stk.push_back(a - b);
                else if (token == "*") stk.push_back(a * b);
                else if (token == "/") stk.push_back(a / b);
            }
        }

        return stk.back();
    }
};
