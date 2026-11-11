class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefix_.reserve(nums.size());
        int sum = 0;
        for (int n : nums) {
            sum += n;
            prefix_.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int preLeft = left > 0 ? prefix_[left - 1] : 0;
        int preRight = prefix_[right];
        return preRight - preLeft;
    }

private:
    std::vector<int> prefix_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */