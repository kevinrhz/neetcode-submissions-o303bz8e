class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> window;
        window.reserve(k);

        int l = 0;
        for (int r = l; r < nums.size(); ++r) {
            if (r - l > k) {
                window.erase(nums[l]);
                ++l;
            }
            if (window.count(nums[r])) { return true; }
            window.insert(nums[r]);
        }
        return false;
    }
};