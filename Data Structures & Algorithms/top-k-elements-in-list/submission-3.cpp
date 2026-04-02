class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1 && k == 1) return {nums[0]};

        std:unordered_map<int, int> freqMap; // num: freq
        freqMap.reserve(nums.size());
        for (const auto& num : nums) {
            ++freqMap[num];
        }

        vector<pair<int, int>> arr; // (freq, num)
        for (const auto& p : freqMap) {
            arr.push_back({p.second, p.first});
        }
        std::sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for (size_t i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};
