class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int h = hand.size();
        int g = groupSize;
        
        if(h % g != 0)
            return false;
        
        map<int, int> mp;
        for(auto it : hand)
            mp[it]++;
        
        sort(hand.begin(), hand.end());
        for(int i = 0; i < h; i++)
        {
            if(mp[hand[i]] == 0)
                continue;
            else
            {
                for(int j = 0; j < g; j++)
                {
                    int here = hand[i] + j;
                    
                    if(mp[here] == 0)
                        return false;
                    
                    mp[here]--;
                }
            }
        }
        
        return true;
    }
};