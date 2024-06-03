class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 1)
            return 0;
        
        vector<int> vis(n, 0);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 1;
        
        while(!q.empty())
        {
            int ind = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(ind == n - 1)
                return steps;
            
            int one = ind + 1;
            int two = ind - 1;
            
            if(one >= 0 && one < n && !vis[one])
            {
                vis[one] = 1;
                q.push({one, steps + 1});
            }
            
            if(two >= 0 && two < n && !vis[two])
            {
                vis[two] = 1;
                q.push({two, steps + 1});
            }
            
            for(auto it : mp[arr[ind]])
            {
                if(it >= 0 && it < n && it != ind && !vis[it])
                {
                    vis[it] = 1;
                    q.push({it, steps + 1});
                }
            }
            mp.erase(arr[ind]);
        }
        
        return false;
    }
};