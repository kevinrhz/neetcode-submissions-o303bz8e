class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 2) return {0, 1}; // only because every input has an answer, else this is dangerous

        std::unordered_map<int, int> seen; // num: index

        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (seen.find(diff) != seen.end()) {
                return {seen[diff], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
