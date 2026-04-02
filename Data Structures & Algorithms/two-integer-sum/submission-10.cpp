class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // target - nums[i] == nums[j]

        std::unordered_map<int, int> numMap; // num: index
        for (size_t i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            
            if (numMap.count(diff)) {
                return {numMap[diff], static_cast<int>(i)};
            } else {
                numMap[nums[i]] = i;
            }
        }
    }
};
