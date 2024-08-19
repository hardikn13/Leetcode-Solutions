class StockPrice {
public:
    int curInd = 1;
    map<int, int> pm;
    unordered_map<int, int> mp;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp) == mp.end())
        {
            mp[timestamp] = price;
            pm[price]++;
        }
        else
        {
            pm[mp[timestamp]]--;
            if(pm[mp[timestamp]] == 0)
                pm.erase(mp[timestamp]);

            mp[timestamp] = price;
            pm[price]++;
        }

        curInd = max(curInd, timestamp);
    }
    
    int current() {
        return mp[curInd];
    }
    
    int maximum() {
        return pm.rbegin() -> first;
    }
    
    int minimum() {
        return pm.begin() -> first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */