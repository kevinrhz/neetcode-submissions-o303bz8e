class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1 && k == 1) return {nums[0]};

        std::unordered_map<int, int> count; // {num: freq}
        count.reserve(nums.size());
        std::vector<std::vector<int>> buckets(nums.size() + 1); // [ i = freq -> [num1], [], [num1, num2], ...]
        std::vector<int> res; // [num1, num2 -> k.length]

        for (const int n : nums) { // {7: 2}
            ++count[n];
        }
        for (const auto& [num, freq] : count) {
            buckets[freq].push_back(num); // [[], [], [7]]
        }

        for (size_t i = buckets.size() - 1; i >= 0; --i) {
            for (const int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
