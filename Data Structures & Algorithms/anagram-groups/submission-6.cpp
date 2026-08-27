class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        groups.reserve(strs.size());
        std::vector<std::vector<std::string>> res;

        for (const std::string& str : strs) {
            std::string sorted_str = str;
            std::sort(sorted_str.begin(), sorted_str.end());
            groups[sorted_str].push_back(str);
        }

        for (const auto& pair : groups) {
            res.push_back(pair.second);
        }

        return res;
    }
};
