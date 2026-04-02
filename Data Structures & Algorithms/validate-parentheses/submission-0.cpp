class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                // c is a closing bracket (main logic)
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                // c is opening bracket (just add to stack)
                stack.push(c);
            }
        }
        return stack.empty();
        // answer is based off stacks state, hashmap simply lets us update stack properly for correct answer
    }
};
