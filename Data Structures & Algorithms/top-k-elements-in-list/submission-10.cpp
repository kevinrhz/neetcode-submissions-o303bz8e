class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. map each number to its frequency
        std::unordered_map<int, int> freq_mp;
        for (const int num : nums) {
            ++freq_mp[num];
        }

        // 2. place each number its a bucket indexed at its frequency
        std::vector<std::vector<int>> buckets(nums.size() + 1); // initialize size so buckets[freq] doesnt segfault
        for (const auto& [num, freq] : freq_mp) {
            buckets[freq].push_back(num);
        }

        // 3. fill result vector until it has k nums. iterate backwards through buckets to grab highest frequencies first
        std::vector<int> res;
        res.reserve(k);
        for (int i = buckets.size() - 1; i > 0; --i) {
            for (const int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
