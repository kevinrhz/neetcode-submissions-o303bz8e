class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        seen.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (seen.count(diff) > 0) return {seen[diff], i};
            seen[nums[i]] = i;
        }
        return {};
    }
};
