#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // 1. Array-based frequency map (Stack allocated, contiguous, extremely fast)
        int count[20001] = {0};
        int unique_count = 0;
        
        for (const int num : nums) {
            if (count[num + 10000] == 0) {
                unique_count++; // Track how many unique numbers we have
            }
            count[num + 10000]++;
        }

        // 2. ONE flat vector for all unique elements. 
        // We reserve exactly the space we need. ZERO re-allocations.
        std::vector<int> unique_nums;
        unique_nums.reserve(unique_count);
        
        for (int i = 0; i < 20001; ++i) {
            if (count[i] > 0) {
                unique_nums.push_back(i - 10000);
            }
        }

        // 3. QuickSelect (std::nth_element)
        // This partitions the array IN-PLACE in O(N) time so the top K elements 
        // are moved to the front of the vector. No nested arrays needed!
        auto comp = [&count](int a, int b) {
            return count[a + 10000] > count[b + 10000];
        };
        
        // nth_element puts the k-th largest element in its correct sorted position,
        // and ensures everything before it is larger (based on our comparator).
        std::nth_element(unique_nums.begin(), unique_nums.begin() + k, unique_nums.end(), comp);
        
        // 4. The first 'k' elements are our answer. 
        // Resize just truncates the logical size, it doesn't reallocate.
        unique_nums.resize(k);
        return unique_nums;
    }
};