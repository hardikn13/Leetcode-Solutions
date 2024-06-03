class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<int> vis(n, 0);
        
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        
        while(!q.empty())
        {
            int ind = q.front();
            q.pop();
            
            if(arr[ind] == 0)
                return true;
            
            int one = ind + arr[ind];
            int two = ind - arr[ind];
            
            if(one >= 0 && one < n && !vis[one])
            {
                vis[one] = 1;
                q.push(one);
            }
            
            if(two >= 0 && two < n && !vis[two])
            {
                vis[two] = 1;
                q.push(two);
            }
        }
        
        return false;
    }
};