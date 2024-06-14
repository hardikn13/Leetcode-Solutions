class Solution {
public:
    int mod = 1e9 + 7;
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        
        return a[0] < b[0];
    }
    
    auto getArea(int x, multiset<pair<int, int>> yLine)
    {
        long long area = 0;
        long long prev = INT_MIN;
        int s = 0;
        
        for(auto &it : yLine)
        {
            s += it.second;
            
            if(s == it.second)
                prev = it.first;
            
            if(s == 0)
                area += (((it.first - prev) % mod) * x) % mod;
        }
        
        return area;
    }
    
    int rectangleArea(vector<vector<int>>& rectangles) {
        
        vector<vector<int>> intervals;
        for(auto it : rectangles)
        {
            intervals.push_back({it[0], 0, it[1], it[3]});
            intervals.push_back({it[2], 1, it[1], it[3]});
        }
        
        sort(intervals.begin(), intervals.end(), cmp);
        int area = 0;
        int prev = INT_MIN;
        multiset<pair<int, int>> yLine;
        
        for(auto &it : intervals)
        {
            if(prev != INT_MIN)
                area = (area + getArea(it[0] - prev, yLine)) % mod;
            
            if(it[1])
            {
                yLine.erase(yLine.find({it[2], 1}));
                yLine.erase(yLine.find({it[3], -1}));
            }
            else
            {
                yLine.insert({it[2], 1});
                yLine.insert({it[3], -1});
            }
            
            prev = it[0];
        }
        
        return area;
    }
};