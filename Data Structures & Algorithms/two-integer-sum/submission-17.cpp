class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
        std::vector<int> res;
        std::unordered_map<int, int> seen; // {diff : index}

        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];

            if (seen.count(diff) > 0) {
                return {seen[diff], i};
            } else {
                seen[nums[i]] = i;
            }
        }

        return {};
    }
};
