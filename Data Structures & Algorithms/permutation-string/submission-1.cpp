class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Optimization: Early exit prevents wasted processing
        if (s1.length() > s2.length()) return false;

        // INFRA OPTIMIZATION 1: Stack Allocation
        // Use a raw array instead of vector<int>.
        // - Vector: Heap allocation (malloc), pointer indirection.
        // - Array: Stack allocation (instant), contiguous L1 cache hits.
        int count[26] = {0};

        // INFRA OPTIMIZATION 2: Single "Balance" Map
        // Instead of s1Count vs s2Count, we track the 'Balance'.
        // s1 increments (Need), s2 decrements (Have).
        // Goal: We want all non-zero balances to eventually become 0.
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        // Calculate initial matches based on the single map
        // matches: How many characters have a perfect '0' balance?
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) matches++;
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26) return true;

            // --- ADD NEW CHARACTER (Right side) ---
            // s2 window moves right -> We 'add' s2[r] to the window.
            // In our balance map, s2 chars are negative. So we DECREMENT.
            int index = s2[r] - 'a';
            count[index]--; 
            
            // Logic: We just subtracted 1.
            // 1. If it BECAME 0, we resolved a discrepancy (gain match).
            // 2. If it WAS 0 (and is now -1), we created a discrepancy (lose match).
            if (count[index] == 0) matches++;
            else if (count[index] == -1) matches--;

            // --- REMOVE OLD CHARACTER (Left side) ---
            // s2 window moves right -> We 'remove' s2[l] from the window.
            // Since s2 chars were negative, 'removing' them means ADDING back.
            index = s2[l] - 'a';
            count[index]++;
            
            // Logic: We just added 1.
            // 1. If it BECAME 0, we resolved a discrepancy.
            // 2. If it WAS 0 (and is now 1), we created a discrepancy.
            if (count[index] == 0) matches++;
            else if (count[index] == 1) matches--;

            l++;
        }

        return matches == 26;
    }
};