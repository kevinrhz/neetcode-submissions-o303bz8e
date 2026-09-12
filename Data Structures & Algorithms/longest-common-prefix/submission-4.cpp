class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string ans = strs[0];
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].size() < ans.size()) {
                ans.resize(strs[i].size());
            }

            for (int j = 0; j < strs[i].size(); ++j) {
                if (ans[j] != strs[i][j]) {
                    ans.resize(j);
                    break;
                }
            }
        }
        return ans;
    }
};