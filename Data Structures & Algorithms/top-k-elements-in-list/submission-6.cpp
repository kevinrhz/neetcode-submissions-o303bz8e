class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count; // {num: freq}
        std::vector<std::vector<int>> buckets(nums.size() + 1); // [[freq 0 vals], [freq 1 vals], ... [freq n vals]]
        std::vector<int> res;

        for (const int num : nums) {
            ++count[num];
        }
        for (const auto& [num, freq] : count) {
            buckets[freq].push_back(num);
        }
        for (int i = buckets.size() - 1; i > 0; --i) {
            for (const int n : buckets[i]) {
                if (res.size() >= k) return res;
                res.push_back(n);
            }
        }
        return res;
    }
};
