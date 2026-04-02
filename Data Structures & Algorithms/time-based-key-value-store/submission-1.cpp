class TimeMap {
private:
    // Store pairs of <timestamp, value>
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}

    // 1. Pass strings by const reference to avoid deep heap copies during function calls
    void set(const string& key, const string& value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }

    string get(const string& key, int timestamp) {
        // 2. Safely check if the key exists without accidentally creating an empty 
        // vector in the map (which map[key] would do under the hood).
        auto it = store.find(key);
        if (it == store.end()) return "";

        // Use const reference to avoid copying the entire vector of history
        const auto& values = it->second;
        
        int l = 0, r = values.size() - 1;
        string res = "";

        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (values[m].first <= timestamp) {
                res = values[m].second; // Save the valid value
                l = m + 1;              // Try to find a more recent one
            } else {
                r = m - 1;              // Timestamp is too far in the future
            }
        }
        return res;
    }
};