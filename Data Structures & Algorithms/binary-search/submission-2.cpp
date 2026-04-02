static const int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int search(const vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
    }
};
