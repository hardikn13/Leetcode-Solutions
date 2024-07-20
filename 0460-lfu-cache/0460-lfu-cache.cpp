class LFUCache {
public:
    map<int, list<vector<int>>> dll;
    unordered_map<int, list<vector<int>>::iterator> mp;
    int n;
    int size;
    LFUCache(int capacity) {
        n = capacity;
        size = 0;
    }

    void makeMostFreqUsed(int key)
    {
        auto &vec = *(mp[key]);
        int value = vec[1];
        int freq = vec[2];

        dll[freq].erase(mp[key]);

        if(dll[freq].empty())
            dll.erase(freq);

        freq++;
        dll[freq].push_front({key, value, freq});
        mp[key] = dll[freq].begin();
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            auto &vec = *(mp[key]);
            int value = vec[1];
            makeMostFreqUsed(key);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(n == 0)
            return;

        if(mp.find(key) != mp.end())
        {
            auto &vec = *(mp[key]);
            vec[1] = value;
            makeMostFreqUsed(key);
        }
        else if(size < n)
        {
            size++;
            
            dll[1].push_front({key, value, 1});
            mp[key] = dll[1].begin();
        }
        else
        {
            auto &l = dll.begin() -> second;
            int k = l.back()[0];
            l.pop_back();

            if(l.empty())
                dll.erase(dll.begin() -> first);

            dll[1].push_front({key, value, 1});
            mp.erase(k);
            mp[key] = dll[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */