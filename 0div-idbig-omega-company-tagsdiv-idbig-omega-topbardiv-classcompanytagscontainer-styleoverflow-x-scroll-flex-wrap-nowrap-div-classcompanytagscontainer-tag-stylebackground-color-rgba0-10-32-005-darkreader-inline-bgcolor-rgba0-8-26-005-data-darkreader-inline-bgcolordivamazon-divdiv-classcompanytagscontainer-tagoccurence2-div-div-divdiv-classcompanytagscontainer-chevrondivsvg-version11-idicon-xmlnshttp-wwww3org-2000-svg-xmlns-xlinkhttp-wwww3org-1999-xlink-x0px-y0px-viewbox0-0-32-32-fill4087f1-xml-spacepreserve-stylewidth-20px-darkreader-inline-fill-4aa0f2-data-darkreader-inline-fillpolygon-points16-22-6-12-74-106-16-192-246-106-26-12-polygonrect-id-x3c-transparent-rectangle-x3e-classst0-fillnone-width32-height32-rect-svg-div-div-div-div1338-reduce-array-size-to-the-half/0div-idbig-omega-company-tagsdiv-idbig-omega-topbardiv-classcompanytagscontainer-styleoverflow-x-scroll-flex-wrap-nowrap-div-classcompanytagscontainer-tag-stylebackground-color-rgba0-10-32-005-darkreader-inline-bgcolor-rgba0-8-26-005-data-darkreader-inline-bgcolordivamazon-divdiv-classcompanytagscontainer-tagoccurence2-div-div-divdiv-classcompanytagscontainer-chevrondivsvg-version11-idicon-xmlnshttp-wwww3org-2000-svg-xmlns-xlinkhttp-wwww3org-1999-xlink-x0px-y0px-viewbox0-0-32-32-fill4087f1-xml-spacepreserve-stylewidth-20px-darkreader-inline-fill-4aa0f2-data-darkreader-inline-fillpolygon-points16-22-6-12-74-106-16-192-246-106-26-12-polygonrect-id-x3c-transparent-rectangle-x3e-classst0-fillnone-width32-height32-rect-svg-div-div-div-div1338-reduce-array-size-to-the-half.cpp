class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<int> v;
        
        for(auto it : arr)
            mp[it]++;
        
        for(auto it : mp)
            v.push_back(it.second);
        
        sort(v.begin(), v.end());
        
        int cnt = 0;
        for(int i = v.size() - 1; i >= 0; i--)
        {
            cnt += v[i];
            if(cnt >= (n + 1) / 2)
                return v.size() - i;
        }
        
        return -1;
    }
};