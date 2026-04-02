class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // target - nums[i] == nums[j]

        std::unordered_map<int, int> numMap; // num: index
        for (size_t i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            
            auto it = numMap.find(diff);
            if (it != numMap.end()) {
                return {it->second, static_cast<int>(i)};
            }
            numMap.insert({nums[i], i});
        }
        return {};
    }
};
