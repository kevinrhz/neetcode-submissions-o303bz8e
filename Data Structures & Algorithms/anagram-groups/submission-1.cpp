class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> strMap; // sorted string: [string1, string2, ...]

        for (const auto& s : strs) {
            string sortedS = s;
            std::sort(sortedS.begin(), sortedS.end());
            strMap[sortedS].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& pair : strMap) {
            res.push_back(pair.second);
        }
        return res;
    }
};
