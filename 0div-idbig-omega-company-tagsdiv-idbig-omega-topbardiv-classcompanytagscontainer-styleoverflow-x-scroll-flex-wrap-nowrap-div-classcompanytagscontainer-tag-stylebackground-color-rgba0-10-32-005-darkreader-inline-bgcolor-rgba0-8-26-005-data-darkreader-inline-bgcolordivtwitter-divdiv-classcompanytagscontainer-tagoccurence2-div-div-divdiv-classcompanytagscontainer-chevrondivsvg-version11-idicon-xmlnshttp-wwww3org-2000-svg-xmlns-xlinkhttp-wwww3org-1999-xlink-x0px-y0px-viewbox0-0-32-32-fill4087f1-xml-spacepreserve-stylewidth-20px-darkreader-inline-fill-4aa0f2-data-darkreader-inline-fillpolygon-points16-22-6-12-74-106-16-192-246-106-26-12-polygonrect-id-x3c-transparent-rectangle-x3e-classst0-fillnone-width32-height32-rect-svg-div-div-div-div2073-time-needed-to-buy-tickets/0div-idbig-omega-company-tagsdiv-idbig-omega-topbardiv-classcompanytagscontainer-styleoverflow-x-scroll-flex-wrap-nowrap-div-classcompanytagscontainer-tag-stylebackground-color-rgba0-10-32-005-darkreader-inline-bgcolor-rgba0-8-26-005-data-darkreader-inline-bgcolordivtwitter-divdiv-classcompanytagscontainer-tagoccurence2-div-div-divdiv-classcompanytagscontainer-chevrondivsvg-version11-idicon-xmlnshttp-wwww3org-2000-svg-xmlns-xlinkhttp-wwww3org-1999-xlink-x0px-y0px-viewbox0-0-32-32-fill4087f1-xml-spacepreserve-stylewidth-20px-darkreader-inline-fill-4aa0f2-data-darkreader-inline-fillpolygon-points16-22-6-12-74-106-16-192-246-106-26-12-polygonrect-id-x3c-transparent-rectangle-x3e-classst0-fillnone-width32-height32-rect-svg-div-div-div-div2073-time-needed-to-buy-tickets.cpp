class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int n = tickets.size();
        int rounds = tickets[k];
        
        int time = 0;
        for(int j = 1; j <= rounds; j++)
        {
            for(int i = 0; i < n; i++)
            {
                if(tickets[i] == 0)
                    continue;
                
                time++;
                tickets[i]--;
                
                if(tickets[k] == 0)
                    return time;
            }   
        }
        
        return 0;
    }
};