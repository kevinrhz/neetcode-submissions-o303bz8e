static const int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 2) return {0, 1};

        std::unordered_map<int, int> seen; // {seen: index}
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
