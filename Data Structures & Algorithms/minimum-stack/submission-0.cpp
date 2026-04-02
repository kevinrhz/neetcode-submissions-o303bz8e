#include <vector>
#include <algorithm>

class MinStack {
private:
    // Direct vector usage: Fastest, simplest, contiguous memory.
    std::vector<int> stack;
    std::vector<int> minStack;

public:
    MinStack() {}

    void push(int val) {
        stack.push_back(val);
        // Optimized: Only push to minStack if new val is <= current min
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }

    void pop() {
        if (stack.empty()) return;
        
        // Sync: check back() instead of top()
        if (stack.back() == minStack.back()) { // if stack and minStack have same top value
            minStack.pop_back(); // pop from minStack (and stack right after)
        }
        stack.pop_back(); // pop from stack
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return minStack.back();
    }
};