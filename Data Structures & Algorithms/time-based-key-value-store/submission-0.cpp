class TimeMap {
public:

    unordered_map<string, vector<pair<int,string>>> mp;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        if (mp.find(key) == mp.end())
            return "";

        vector<pair<int,string>> &arr = mp[key];

        int l = 0;
        int r = arr.size() - 1;

        // No timestamp <= query
        if (arr[l].first > timestamp)
            return "";

        // Largest timestamp already fits
        if (arr[r].first <= timestamp)
            return arr[r].second;

        // Transition point:
        // Before : timestamp <= query
        // After  : timestamp > query

        while (r - l > 1) {

            int mid = l + (r - l) / 2;

            if (arr[mid].first <= timestamp)
                l = mid;
            else
                r = mid;
        }

        return arr[l].second;
    }
};