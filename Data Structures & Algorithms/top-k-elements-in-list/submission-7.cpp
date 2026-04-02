class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int count[20001] = {0}; // {num: freq}
        int max_freq = 0;
        std::vector<std::vector<int>> buckets(nums.size() + 1); // [[freq 0 vals], [freq 1 vals], ... [freq n vals]]
        std::vector<int> res;
        res.reserve(k);

        for (const int num : nums) {
            int freq = ++count[num + 10000];
            if (freq > max_freq) max_freq = freq;
        }
        for (int i = 0; i < 20001; ++i) {
            if (count[i] > 0) {
                buckets[count[i]].push_back(i - 10000);
            }
        }
        for (int i = max_freq; i > 0 && res.size() < k; --i) {
            for (const int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
