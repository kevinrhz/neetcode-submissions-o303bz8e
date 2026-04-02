class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Edge Case: If s1 is bigger, it can't be a substring of s2.
        if (s1.length() > s2.length()) return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        // 1. INITIALIZATION PHASE
        // Build the frequency map for s1 (Target)
        // AND build the map for the VERY FIRST window of s2 (Current)
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // 2. CALCULATE INITIAL MATCHES
        // Count how many letters (a-z) satisfy the requirement right now.
        // If matches == 26, the first window is already a permutation.
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        // 3. SLIDING WINDOW PHASE
        // Start sliding 'r' from the first character OUTSIDE the initial window.
        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            // Check if previous window was a winner
            if (matches == 26) return true;

            // --- ADD NEW CHARACTER (Right side) ---
            int index = s2[r] - 'a';
            s2Count[index]++;
            
            // Did adding this char make the count perfect?
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } 
            // Did adding this char break a previously perfect count?
            // (We now have 1 too many of this char)
            else if (s1Count[index] + 1 == s2Count[index]) {
                matches--;
            }

            // --- REMOVE OLD CHARACTER (Left side) ---
            index = s2[l] - 'a';
            s2Count[index]--;
            
            // Did removing this char make the count perfect?
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } 
            // Did removing this char break a previously perfect count?
            // (We now have 1 too few of this char)
            else if (s1Count[index] - 1 == s2Count[index]) {
                matches--;
            }
            
            l++; // Move left pointer forward
        }

        // Check the very last window after the loop finishes
        return matches == 26;
    }
};