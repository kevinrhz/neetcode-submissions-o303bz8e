const static int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if ((n % 2 != 0) || (n <= 1)) return false; // Odd length strings can never be valid (must be pairs), also cant be <= 1

        // OPTIMIZATION 1: Vector as Stack + Reserve
        // - std::stack: Uses std::deque by default (complex allocation).
        // - std::vector: Contiguous memory. 
        // - .reserve(n): Allocates ALL memory upfront. Zero re-allocations during the loop.
        std::vector<char> stack;
        stack.reserve(n);

        for (const char c : s) {
            // OPTIMIZATION 2: Logic Branching vs Map
            // - Map: Hashing overhead or tree lookup (Slow).
            // - Switch/If: CPU checks registers directly (Fast).
            switch (c) {
                case '(':
                case '{':
                case '[':
                    stack.push_back(c);
                    break;
                case ')':
                    if (stack.empty() || stack.back() != '(') return false;
                    stack.pop_back();
                    break;
                case '}':
                    if (stack.empty() || stack.back() != '{') return false;
                    stack.pop_back();
                    break;
                case ']':
                    if (stack.empty() || stack.back() != '[') return false;
                    stack.pop_back();
                    break;
            }
        }
        return stack.empty(); // return state of stack, anything lingering means it didnt have a match to pop it off
    }
};
