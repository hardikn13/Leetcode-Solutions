class MapSum {
public:
    unordered_map<string, int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int n = prefix.size();
        int ans = 0;
        for(auto it : mp)
        {
            if(it.first.substr(0, n) == prefix)
            {
                ans += it.second;
            }
        }

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */