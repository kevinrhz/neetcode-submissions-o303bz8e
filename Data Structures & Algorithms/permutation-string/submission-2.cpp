class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Edge case: s1 cannot be inside s2 if it's larger
        if (s1.size() > s2.size()) return false;

        // Infra Optimization: Stack-allocated array for instant O(1) access
        // Initialized to {0} (implicit 'memset' without the header)
        int count[26] = {0};
        
        // Build Initial Balance Map for the first window:
        // s1 adds to the pile (+), s2 digs from the pile (-)
        for (int i = 0; i < s1.size(); ++i) {
            ++count[s1[i] - 'a'];
            --count[s2[i] - 'a'];
        }

        // Calculate initial score: How many chars are perfectly balanced (0)?
        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) ++matches;
        }

        int l = 0;
        // Slide window starting from the first character *outside* the initial set
        for (int r = s1.size(); r < s2.size(); ++r) {
            // Check if the PREVIOUS window was a winner
            if (matches == 26) return true;

            // --- Right Pointer (Incoming Char) ---
            // We have MORE of this char now. "Dig deeper" (Decrement).
            int index = s2[r] - 'a';
            --count[index];
            if (count[index] == 0) ++matches;      // We hit the perfect balance
            else if (count[index] == -1) --matches;// We just dug too deep (broke zero)

            // --- Left Pointer (Outgoing Char) ---
            // We have LESS of this char now. "Fill back up" (Increment).
            index = s2[l] - 'a';
            ++count[index];
            if (count[index] == 0) ++matches;      // We hit the perfect balance
            else if (count[index] == 1) --matches; // We filled too much (broke zero)

            ++l;
        }
        // Check the very last window state
        return matches == 26;
    }
};