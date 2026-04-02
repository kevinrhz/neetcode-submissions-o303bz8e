class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";

        vector<int> sizes; // [size1, size2, ... sizeN]
        string res = "";

        // create and append sizes header to res string
        for (string& s : strs) {
            sizes.push_back(s.size());
        }
        for (int sz : sizes) {
            res += to_string(sz) + ',';
        }

        // append header -> body separator
        res += '#';

        // append string body strings
        for (string& s : strs) {
            res += s;
        }
        return res; // "5,5,#HelloWorld"
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        std::vector<int> sizes;
        std::vector<string> res;

        int i = 0;
        while (s[i] != '#') {
            string cur = "";
            while (s[i] != ',') {
                cur += s[i];
                ++i;
            }
            sizes.push_back(stoi(cur));
            ++i;
        }
        ++i;
        
        for (int sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }
        return res;
    }
};
