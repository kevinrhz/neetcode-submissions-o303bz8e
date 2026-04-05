class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res;
        for (std::string& s : strs) {
            res += std::to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        std::vector<std::string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            // place j on delimiter
            while (s[j] != '#') ++j;

            // extract the length substr
            int len = std::stoi(s.substr(i, j - i));

            // build res and update i position
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;

        }
        return res;
    }
};
