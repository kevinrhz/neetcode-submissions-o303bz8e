class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> mp;

        for (const auto& s : strs) {
            // build strings character count array
            int count[26] = {0};
            for (const char c : s) {
                ++count[c - 'a'];
            }

            // convert array to string with delimiter to store as key in mp
            std::string key = std::to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + std::to_string(count[i]);
            }
            mp[key].push_back(s);
        }

        // populate a nested vector with results to return
        std::vector<std::vector<std::string>> res;
        for (const auto& [key, values] : mp) {
            res.push_back(values);
        }
        return res;
    }
};
