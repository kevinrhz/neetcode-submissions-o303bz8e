class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> stringMap; // "keyString": ["string1", "string2"]
        std::vector<std::vector<string>> res; // [[anagrams1], [anagrams2], ...]
        
        for (const auto& s : strs) {
            std::vector<int> count(26, 0); // [1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0]
            for (const char c : s) {
                ++count[c - 'a'];
            }
            
            string key = to_string(count[0]); // "1" -> "1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0"
            for (size_t i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            stringMap[key].push_back(s); // {"1,0,1,0,0,0,0,0,1,0,0,0,0": ["act, "cat"]}
        }
        for (const auto& [key, values] : stringMap) {
            res.push_back(values);
        }
        return res;
    }
};
