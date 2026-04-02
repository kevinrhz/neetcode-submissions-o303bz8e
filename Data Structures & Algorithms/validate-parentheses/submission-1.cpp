class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (const char c : s) {
            if (closeToOpen.count(c)) { // c is a closing bracket (main logic)
                if (!stack.empty() && stack.top() == closeToOpen[c]) { // if current char is a matching closing bracket, then popping removes its match
                    stack.pop();
                } else return false; // else it doesnt having a matching bracket (empty or wrong match)
            } else { // c is an opening bracket
                stack.push(c); // just add to stack
            }
        }
        return stack.empty(); // return state of stack, anything lingering means it didnt have a match to pop it off
    }
};
