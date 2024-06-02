class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());
        
        int ans = 0, z = 0, start = meetings[0][0], end = 0;
        ans += start - 1;
        for(auto it : meetings)
        {
            if(it[0] <= end + 1 || z == 0)
            {
                if(it[1] > end)
                    end = it[1];
                z = 1;
            }
            else
            {
                ans += it[0] - end - 1;
                end = it[1];
            }
        }
        ans += (days - end);
        
        return ans;
    }
};