class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        
        int cnt = 0, ans = 0;
        for(auto it : mp)
        {
            cnt += it.second;
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */