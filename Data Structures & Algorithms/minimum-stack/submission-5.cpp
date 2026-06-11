class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        stk.push_back(val);
        if (minStk.empty() || val <= minStk.back()) {
            minStk.push_back(val);
        }
    }
    
    void pop() {
        if (!minStk.empty() && stk.back() == minStk.back()) {
            minStk.pop_back();
        }
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return !minStk.empty() ? minStk.back() : 0;
    }

private:
    std::vector<int> stk;
    std::vector<int> minStk;
};
