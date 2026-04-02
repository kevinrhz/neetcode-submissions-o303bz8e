class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());

        for (const int n : nums) {
            if (seen.find(n) != seen.end()) {
                return true;
            }
            seen.insert(n);
        }
        return false;
    }
};