class Solution {
public:
    string encode(vector<string>& strs) {
        // 1. Memory Pre-allocation (Prevent dynamic resizing)
        // We calculate a safe upper bound for the total string size.
        size_t total_capacity = 0;
        for (const string& s : strs) {
            // Max 10 chars for a 32-bit int length + 1 char for '#' + payload length
            total_capacity += 10 + 1 + s.size(); 
        }
        
        string res;
        res.reserve(total_capacity); // Exactly ONE heap allocation for the result string
        
        for (const string& s : strs) {
            // Note: std::to_string creates a temporary string, but because string 
            // lengths are small numbers (e.g., "5"), they easily fit in SSO 
            // (Small String Optimization), meaning no heap allocation happens here!
            res += std::to_string(s.size());
            res += '#';
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int n = s.size();
        
        while (i < n) {
            // 2. In-Place Integer Parsing (Zero Allocations)
            // We DO NOT use s.substr() or std::stoi() here. 
            // Doing so creates a temporary string on the heap for every single word.
            int len = 0;
            while (s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }
            
            i++; // Skip the '#' delimiter
            
            // 3. Payload Extraction
            // We are forced to allocate here because the function signature 
            // requires returning a vector of std::string.
            res.push_back(s.substr(i, len));
            i += len;
        }
        
        return res;
    }
};