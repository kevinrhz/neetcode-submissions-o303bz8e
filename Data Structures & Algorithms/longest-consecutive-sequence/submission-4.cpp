class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        int res = 0;

        for (const int num: nums) {
            if (mp[num]) continue;

            int len = mp[num - 1] + mp[num + 1] + 1;
            mp[num] = len;

            mp[num - mp[num - 1]] = len;
            mp[num + mp[num + 1]] = len;

            res = std::max(res, mp[num]);
        }
        return res;
    }
};
