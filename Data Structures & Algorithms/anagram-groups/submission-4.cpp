class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mp; // {key strs: [associated strs]}
        std::vector<std::vector<std::string>> res;
        
        for (const std::string& str : strs) {
            int count[26] = {0}; // [1,0,1,0,0,0,0,1,0,0,0,0]
            for (const char c : str) {
                ++count[c - 'a'];
            }

            std::string key = std::to_string(count[0]); // "1,0,1,0,0,0,0,1,0,0,0"
            for (int i = 1; i < 26; ++i) {
                key += ',' + std::to_string(count[i]);
            }
            mp[key].push_back(str);
        }

        for (const auto& [key, values] : mp) {
            res.push_back(values);
        }
        return res;
    }
};
