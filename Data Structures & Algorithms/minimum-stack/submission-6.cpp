class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        stk.push_back(val);
        minStk.push_back(!minStk.empty() ? std::min(val, minStk.back()) : val);
    }
    
    void pop() {
        stk.pop_back();
        minStk.pop_back();
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
