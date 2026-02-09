class TimeMap {
public:
    map<string, vector<pair<string,int>>> m1;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        if(key.empty() || value.empty() || timestamp==0) return;
        m1[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!m1.count(key)) return "";
        vector<pair<string,int>> &v1 = m1[key]; 
        string ans = "";
        int low = 0, high = v1.size() - 1; 
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(v1[mid].second <= timestamp) {
                ans = v1[mid].first;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
