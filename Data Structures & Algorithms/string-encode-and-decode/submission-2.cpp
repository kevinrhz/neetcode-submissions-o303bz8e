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
        while (s[i] != '#') { // iterate over header
            string cur = "";
            while (s[i] != ',') {
                cur += s[i]; // add number to cur
                ++i;
            }
            sizes.push_back(stoi(cur)); // store number from cur
            ++i; // hop over comma
        }
        ++i; // hop over # separator into body
        
        for (int sz : sizes) { // iterate over body adding each word to res
            res.push_back(s.substr(i, sz));
            i += sz;
        }
        return res;
    }
};
