class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::vector<int> seen(nums.size(), 0);

        for (const int n : nums) {
            if (seen[n - 1] == 1) return n;
            ++seen[n - 1];
        }
        return -1;
    }
};
