class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        mp.reserve(nums.size());
        int res = 0;

        for (const int num: nums) {
            if (mp[num]) continue;

            int len = mp[num - 1] + mp[num + 1] + 1;
            mp[num] = len;               // update self
            mp[num - mp[num - 1]] = len; // update left boundary
            mp[num + mp[num + 1]] = len; // update right boundary

            res = std::max(res, mp[num]);
        }
        return res;
    }
};
