class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen; // value: index
        seen.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];

            auto it = seen.find(diff);
            if (it != seen.end()) {
                return {it->second, i};
            }

            seen[nums[i]] = i;
        }
        return {};
    }
};
