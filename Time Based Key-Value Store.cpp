class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";

         auto &v = mp[key];

        string res = "";
        int l = 0, h = v.size() - 1;

        while(l <= h){
            int mid = l + (h-l)/2;
            if(v[mid].first == timestamp) return v[mid].second;
            else if(v[mid].first <= timestamp){
                res = v[mid].second;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
