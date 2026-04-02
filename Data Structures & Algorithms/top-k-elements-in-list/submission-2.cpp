class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap; // val: freq
        freqMap.reserve(nums.size());
        for (auto num : nums) {
            ++freqMap[num];
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1); // [freq [nums] ]
        for (auto const& [val, freq] : freqMap) {
            buckets[freq].push_back(val);
        }

        std::vector<int> res;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return {};
    }
};
