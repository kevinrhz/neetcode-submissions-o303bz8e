class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;
public:
    TimeMap() {}
    
    void set(const string& key, const string& value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(const string& key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";

        const auto& values = it->second;

        int l = 0, r = values.size() - 1;
        std::string res = "";
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (values[m].first <= timestamp) {
                res = values[m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};
