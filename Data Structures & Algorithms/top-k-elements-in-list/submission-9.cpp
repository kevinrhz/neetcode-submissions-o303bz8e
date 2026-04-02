#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = nums.size();

        // ---------------------------------------------------------
        // PHASE 1: Build the Frequency Map (Stack allocated, O(1))
        // ---------------------------------------------------------
        int count[20001] = {0};
        int max_freq = 0;
        int unique_elements = 0;

        for (int num : nums) {
            if (count[num + 10000] == 0) unique_elements++;
            int freq = ++count[num + 10000];
            if (freq > max_freq) max_freq = freq;
        }

        // ---------------------------------------------------------
        // PHASE 2: Size the Buckets (Counting Sort Logic)
        // Instead of creating vectors, we just count HOW MANY elements 
        // will go into each frequency bucket.
        // ---------------------------------------------------------
        std::vector<int> freq_count(max_freq + 1, 0);
        for (int i = 0; i < 20001; ++i) {
            if (count[i] > 0) {
                freq_count[count[i]]++;
            }
        }

        // ---------------------------------------------------------
        // PHASE 3: Prefix Sums for Offsets
        // Calculate the starting index for each bucket in our FLAT array.
        // offset[f] tells us the exact array index to place the first 
        // element that has a frequency of 'f'.
        // ---------------------------------------------------------
        std::vector<int> offset(max_freq + 1, 0);
        int current_position = 0;
        for (int f = 1; f <= max_freq; ++f) {
            offset[f] = current_position;
            current_position += freq_count[f]; 
        }

        // ---------------------------------------------------------
        // PHASE 4: Populate the Flat Bucket Array
        // We place items into flat_buckets using the offsets, then 
        // increment the offset so the next item goes in the slot next to it.
        // ---------------------------------------------------------
        std::vector<int> flat_buckets(unique_elements);
        for (int i = 0; i < 20001; ++i) {
            if (count[i] > 0) {
                int f = count[i];
                flat_buckets[offset[f]++] = i - 10000;
            }
        }

        // ---------------------------------------------------------
        // PHASE 5: Gather Results
        // Because of how we built the offsets, elements with frequency 1 
        // are at the start of the array, and elements with max_freq 
        // are at the VERY END. We just read it backwards!
        // ---------------------------------------------------------
        std::vector<int> res;
        res.reserve(k);
        
        for (int i = unique_elements - 1; i >= 0 && res.size() < k; --i) {
            res.push_back(flat_buckets[i]);
        }

        return res;
    }
};