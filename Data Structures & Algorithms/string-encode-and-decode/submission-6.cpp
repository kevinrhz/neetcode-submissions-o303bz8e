class Solution {
public:

    string encode(vector<string>& strs) { // ["eat", "donuts"]
        if (strs.size() == 0) return "";
        std::string res = "";

        for (const std::string& s : strs) {
            res += std::to_string(s.length()) + '#' + s;
        }
        return res; // "3#eat6#donuts"
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        std::vector<std::string> res;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') ++j;
            int len = std::stoi(s.substr(i, j - i)); // j - i length is important to capture strings size double, triple digits, i.e. 10, 100 length
            i = j + 1;
            j = i + len;
            res.push_back(s.substr(i, len));
            i = j;
        }
        return res;
    }
};
