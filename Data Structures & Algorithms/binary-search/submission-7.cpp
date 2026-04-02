class Solution {
public:
    int search(const vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        return (!nums.empty() && *it == target) ? it - nums.begin() : -1;
    }
};
