class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, const int k) {
        std::unordered_map<int, int> freqMap; // {value : freq}
        freqMap.reserve(nums.size());
        for (const int n : nums) { ++freqMap[n]; }

        std::vector<std::vector<int>> buckets(nums.size() + 1);
        buckets.reserve(freqMap.size());
        for (const auto& pair : freqMap) {
            buckets[pair.second].push_back(pair.first);
        }

        std::vector<int> res;
        res.reserve(k);
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (const int num : buckets[i]) {
                if (res.size() < k) {
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};
