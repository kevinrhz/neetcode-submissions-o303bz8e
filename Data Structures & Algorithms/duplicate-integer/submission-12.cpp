class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> nums_set;
        for (const int& num : nums) {
            nums_set.insert(num);
        }
        return nums_set.size() < nums.size();
    }
};