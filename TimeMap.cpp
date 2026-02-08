class TimeMap {
public:
    map<string, vector<pair<string,int>>> m1;
    set<int>s1;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(value=="" || key== "" || timestamp == 0)
        {
            return;
        }
        m1[key].push_back({value, timestamp});
        s1.insert(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(!m1.count(key))
        {
            return "";
        }
        string ans="";
        vector<pair<string,int>>v1;
        v1=m1[key];
        for(auto &it:m1[key])
        {
            if(it.second <=timestamp)
            {
                ans=it.first;
            }
        }
        return ans;
    }
};
