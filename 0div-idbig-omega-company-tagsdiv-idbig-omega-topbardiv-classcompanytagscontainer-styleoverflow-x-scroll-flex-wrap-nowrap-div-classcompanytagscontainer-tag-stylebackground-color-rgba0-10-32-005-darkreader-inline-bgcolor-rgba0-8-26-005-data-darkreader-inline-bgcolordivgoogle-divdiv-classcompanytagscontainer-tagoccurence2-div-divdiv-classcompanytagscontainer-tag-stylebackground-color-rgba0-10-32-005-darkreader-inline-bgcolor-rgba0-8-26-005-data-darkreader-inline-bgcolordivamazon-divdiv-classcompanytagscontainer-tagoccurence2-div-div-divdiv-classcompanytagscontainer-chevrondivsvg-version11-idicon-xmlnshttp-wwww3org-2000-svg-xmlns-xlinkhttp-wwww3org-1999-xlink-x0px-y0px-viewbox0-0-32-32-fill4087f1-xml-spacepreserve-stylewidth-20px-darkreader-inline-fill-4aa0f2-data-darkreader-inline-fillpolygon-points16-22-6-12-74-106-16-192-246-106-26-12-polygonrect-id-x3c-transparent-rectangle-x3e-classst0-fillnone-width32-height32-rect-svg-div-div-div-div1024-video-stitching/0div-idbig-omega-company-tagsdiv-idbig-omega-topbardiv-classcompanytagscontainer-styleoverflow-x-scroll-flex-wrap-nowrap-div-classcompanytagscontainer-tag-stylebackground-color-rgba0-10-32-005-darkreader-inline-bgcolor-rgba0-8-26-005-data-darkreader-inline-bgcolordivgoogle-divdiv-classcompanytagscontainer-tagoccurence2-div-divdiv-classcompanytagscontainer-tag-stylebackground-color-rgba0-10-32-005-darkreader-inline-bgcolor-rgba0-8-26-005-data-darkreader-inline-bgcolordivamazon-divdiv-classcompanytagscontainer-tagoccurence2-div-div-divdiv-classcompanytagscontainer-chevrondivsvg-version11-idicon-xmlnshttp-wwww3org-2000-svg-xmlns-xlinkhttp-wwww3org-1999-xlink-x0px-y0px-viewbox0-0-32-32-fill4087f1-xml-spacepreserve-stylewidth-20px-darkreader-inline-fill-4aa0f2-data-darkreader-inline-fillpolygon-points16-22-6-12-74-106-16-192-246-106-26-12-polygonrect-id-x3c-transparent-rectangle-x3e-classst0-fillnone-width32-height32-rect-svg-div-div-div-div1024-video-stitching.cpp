class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        
        return a[0] < b[0];
    }
    
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        sort(clips.begin(), clips.end(), cmp);
        
        int ans = 0, farthest = 0, end = 0, i = 0;
        while(end < time)
        {
            ans++;
            farthest = end;
            
            while(i < clips.size() && clips[i][0] <= end)
            {
                farthest = max(farthest, clips[i][1]);
                i++;
            }
            
            if(farthest == end)
                return -1;
            
            end = farthest;
        }
        
        return ans;
    }
};