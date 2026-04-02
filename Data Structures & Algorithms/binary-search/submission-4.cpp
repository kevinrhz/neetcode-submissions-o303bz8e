class Solution {
public:
    int search(const vector<int>& nums, int target) {
        const auto it = std::lower_bound(nums.begin(), nums.end(), target);
        return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
    }
};
