class MinStack {
private:
    std::vector<int> stack, minStack;

public:
    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
        if (minStack.empty() || val <= minStack.back()) minStack.push_back(val);
    }
    
    void pop() {
        if (stack.empty()) return;
        if (minStack.back() == stack.back()) minStack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
