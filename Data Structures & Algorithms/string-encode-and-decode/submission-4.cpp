class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (const string& s : strs) { // loop through string and append len,delimiter,word for each word
            res += to_string(s.length()) + '#' + s;
        }
        return res;
    } // "5#Hello5#World"

    vector<string> decode(string s) {
        std::vector<string> res;
        int i = 0;
        while (i < s.size()) { // iterate over the encoded string
            int j = i;
            while (s[j] != '#') { // use second pointer j to find the # delimiter
                ++j;
            } // i = 0, j = 1
            int len = stoi(s.substr(i, j - i)); // len = <int>5
            i = j + 1; // i = 2
            j = i + len; // j = 7
            res.push_back(s.substr(i, len)); // push back "Hello"
            i = j; // i = 7, j = 7
        }
        return res;
    }
};
