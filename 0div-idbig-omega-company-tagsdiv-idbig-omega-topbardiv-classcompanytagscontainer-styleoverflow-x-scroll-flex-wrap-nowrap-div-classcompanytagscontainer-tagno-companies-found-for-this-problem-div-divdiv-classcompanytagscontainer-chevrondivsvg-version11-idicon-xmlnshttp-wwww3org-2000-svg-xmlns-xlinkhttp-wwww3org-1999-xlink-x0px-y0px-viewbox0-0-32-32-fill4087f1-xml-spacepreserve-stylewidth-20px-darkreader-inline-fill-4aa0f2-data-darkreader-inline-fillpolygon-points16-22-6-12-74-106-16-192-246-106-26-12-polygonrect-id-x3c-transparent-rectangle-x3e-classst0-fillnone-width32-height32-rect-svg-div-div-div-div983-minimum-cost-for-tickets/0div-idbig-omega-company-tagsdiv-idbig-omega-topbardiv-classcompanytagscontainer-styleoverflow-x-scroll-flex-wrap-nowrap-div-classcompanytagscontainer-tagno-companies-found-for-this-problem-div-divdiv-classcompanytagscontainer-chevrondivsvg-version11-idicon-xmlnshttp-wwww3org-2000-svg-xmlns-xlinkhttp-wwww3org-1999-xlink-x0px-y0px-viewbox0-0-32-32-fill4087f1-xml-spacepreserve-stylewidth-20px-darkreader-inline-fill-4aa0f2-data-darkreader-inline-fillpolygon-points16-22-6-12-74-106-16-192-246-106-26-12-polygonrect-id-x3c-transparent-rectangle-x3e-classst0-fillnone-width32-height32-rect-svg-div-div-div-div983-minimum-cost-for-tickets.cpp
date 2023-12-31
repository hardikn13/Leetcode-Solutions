class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        unordered_set<int> st;
        vector<int> dp(366, 0);
        
        for (auto it : days)
            st.insert(it);
        
        for (int ind = days[0]; ind <= 365; ind++) {
            if(st.find(ind) == st.end()) 
            {
                dp[ind] = dp[ind - 1];
                continue;
            }

            int w1 = costs[0] + (ind - 1 >= 0 ? dp[ind - 1] : 0);
            int w2 = costs[1] + (ind - 7 >= 0 ? dp[ind - 7] : 0);
            int w3 = costs[2] + (ind - 30 >= 0 ? dp[ind - 30] : 0);


            dp[ind] = min(w1, min(w2, w3));
        }
        
        return dp[365];
    }
};
