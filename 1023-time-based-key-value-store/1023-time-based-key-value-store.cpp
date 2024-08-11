class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        auto &it = mp[key];
        int low = 0, high = it.size() - 1;
        string result = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (it[mid].second <= timestamp) {
                result = it[mid].first;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
