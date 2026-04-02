static const int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Optimization 1: Use vector as a stack for cache locality.
        // Reserve space to avoid resizing overhead. Max stack depth <= tokens.size() / 2 + 1.
        vector<int> stack;
        stack.reserve(tokens.size() / 2 + 1);

        for (const string& token : tokens) {
            // Optimization 2: Fast Token Identification
            // If length > 1 (e.g., "-5", "10") OR it's a digit ("5"), it's a number.
            // This avoids slow string comparisons.
            if (token.size() > 1 || isdigit(token[0])) {
                stack.push_back(stoi(token));
                continue;
            }

            // If we are here, it's definitely a single-char operator.
            // Pop the top two values (no safety checks needed per problem constraints).
            int b = stack.back(); stack.pop_back();
            int a = stack.back(); stack.pop_back();

            // Optimization 3: Switch Case (compiles to a Jump Table)
            switch (token[0]) {
                case '+': stack.push_back(a + b); break;
                case '-': stack.push_back(a - b); break;
                case '*': stack.push_back(a * b); break;
                case '/': stack.push_back(a / b); break;
            }
        }
        return stack.back();
    }
};
