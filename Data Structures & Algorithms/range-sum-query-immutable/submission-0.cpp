class NumArray {
public:
    NumArray(const vector<int>& nums) {
        int total = 0;
        for (const int n : nums) {
            total+= n;
            prefix.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        int preRight = prefix[right];
        int preLeft = left > 0 ? prefix[left - 1] : 0;
        return preRight - preLeft;
    }

private:
    std::vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */