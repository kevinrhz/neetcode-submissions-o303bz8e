class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        groups.reserve(strs.size());

        for (const std::string& s : strs) {
            std::string sorted_str = s;
            std::sort(sorted_str.begin(), sorted_str.end());
            groups[sorted_str].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        res.reserve(groups.size());
        for (const auto& pair : groups) {
            res.push_back(std::move(pair.second));
        }

        return res;
    }
};
