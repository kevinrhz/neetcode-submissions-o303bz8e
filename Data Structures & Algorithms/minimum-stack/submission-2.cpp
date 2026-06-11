class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        std::vector<int> tmpStack;
        int minVal = stack.back();
        while (stack.size()) {
            minVal = std::min(minVal, stack.back());
            tmpStack.push_back(stack.back());
            stack.pop_back();
        }

        while (tmpStack.size()) {
            stack.push_back(tmpStack.back());
            tmpStack.pop_back();
        }

        return minVal;
    }

private:
    std::vector<int> stack;
};
