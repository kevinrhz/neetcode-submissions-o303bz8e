class Solution {
public:
    static 

    string encode(const vector<string>& strs) {
        std::string res;
        res.reserve(100 * 200);

        for (const std::string& s : strs) {
            res.append(std::to_string(s.size())+ "#" + s);
        }
        return res;
    }

    vector<string> decode(const string& s) {
        std::vector<std::string> res;
        res.reserve(100);

        int i = 0;
        while (i < s.size()) {
            int delim_pos = s.find('#', i);
            int len = std::stoi(s.substr(i, delim_pos - i));
            
            std::string word = s.substr(delim_pos + 1, len);
            res.push_back(std::move(word));
            
            i = delim_pos + 1 + len;
        }
        
        return res;
    }
};
