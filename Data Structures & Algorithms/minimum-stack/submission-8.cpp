class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        if (minStk.empty() || val <= minStk.back()) {
            minStk.push_back(val);
        }
        stk.push_back(val);
    }
    
    void pop() {
        if (minStk.empty() || minStk.back() >= stk.back()) {
            minStk.pop_back();
        }
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minStk.back();
    }

private:
    std::vector<int> stk;
    std::vector<int> minStk;
};
