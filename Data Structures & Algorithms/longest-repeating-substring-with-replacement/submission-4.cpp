class Solution {
public:
    // 1. Pass by const reference! No heap copies.
    int characterReplacement(const string& s, int k) {
        
        // 2. Flat stack-allocated array for our 26 possible characters
        int count[26] = {0};
        
        int l = 0;
        int max_freq = 0; // Tracks the most frequent char in our CURRENT window
        int res = 0;

        for (int r = 0; r < s.size(); ++r) {
            // Add right character to our window's frequency map
            int right_char = s[r] - 'A';
            count[right_char]++;
            
            // Update the highest frequency we've seen in this window
            max_freq = std::max(max_freq, count[right_char]);

            // Window size is (r - l + 1). 
            // If Window Size - most frequent character > k, the window is invalid.
            if ((r - l + 1) - max_freq > k) {
                // Remove the left character from our frequency map and shrink window
                count[s[l] - 'A']--;
                ++l;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};