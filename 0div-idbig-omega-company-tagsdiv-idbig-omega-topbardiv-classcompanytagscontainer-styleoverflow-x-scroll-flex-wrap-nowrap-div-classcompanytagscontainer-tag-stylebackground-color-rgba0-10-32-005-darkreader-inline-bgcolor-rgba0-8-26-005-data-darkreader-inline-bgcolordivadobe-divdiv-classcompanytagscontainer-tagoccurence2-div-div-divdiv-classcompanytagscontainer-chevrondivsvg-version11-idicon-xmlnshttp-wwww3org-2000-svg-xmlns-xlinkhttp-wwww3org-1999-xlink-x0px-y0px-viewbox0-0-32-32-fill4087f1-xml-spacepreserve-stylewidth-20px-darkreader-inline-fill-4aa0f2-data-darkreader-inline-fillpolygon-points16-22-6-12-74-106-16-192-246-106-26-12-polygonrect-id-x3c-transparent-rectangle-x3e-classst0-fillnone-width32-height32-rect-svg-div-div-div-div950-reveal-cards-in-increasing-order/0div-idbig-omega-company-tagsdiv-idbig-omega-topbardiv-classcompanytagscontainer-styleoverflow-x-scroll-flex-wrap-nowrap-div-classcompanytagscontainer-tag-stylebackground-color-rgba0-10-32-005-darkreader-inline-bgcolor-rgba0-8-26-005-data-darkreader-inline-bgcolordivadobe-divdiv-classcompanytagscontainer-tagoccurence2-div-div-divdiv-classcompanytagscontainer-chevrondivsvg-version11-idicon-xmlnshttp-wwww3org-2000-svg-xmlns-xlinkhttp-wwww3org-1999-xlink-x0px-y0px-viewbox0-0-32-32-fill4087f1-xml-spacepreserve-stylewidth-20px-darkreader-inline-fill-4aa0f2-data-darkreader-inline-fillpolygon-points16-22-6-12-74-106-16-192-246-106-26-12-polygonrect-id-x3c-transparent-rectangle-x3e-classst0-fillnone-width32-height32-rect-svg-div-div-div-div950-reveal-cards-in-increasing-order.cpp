class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> dq;
        int i = n - 1;
        int cnt = 0;
        
        while(i >= 0)
        {
            if(cnt > 1)
            {
                int ele = dq.back();
                dq.pop_back();
                dq.push_front(ele);
            }
            dq.push_front(deck[i]);
            
            i--;
            cnt++;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        
        return ans;
    }
};