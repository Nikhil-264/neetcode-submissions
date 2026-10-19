class TimeMap {
public:
    unordered_map<string, unordered_map<int, vector<string>>> mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }
        int seen = -1;
        for(const auto& [time, _] : mp[key]){
            if(time <= timestamp){
                seen = max(seen, time);
            }
        }
        return seen == -1 ? "" : mp[key][seen].back();
    }
};
