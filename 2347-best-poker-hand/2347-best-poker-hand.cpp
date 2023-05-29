class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int p = 0, q = 0, max = 0;
        for(int i = 1; i < suits.size(); i++)
        {
            if(suits[i]==suits[i-1])
            {
                p++;
                if(p==4)
                {
                    string s1 = "Flush";
                    return s1;
                }
            }
            else
            {
                break;
            }
        }
        sort(ranks.begin(), ranks.end());
        for(int j = 0; j < ranks.size() - 1; j++)
        {
            if(ranks[j]==ranks[j+1])
            {
                q++;
                if(q > max)
                    max = q;
                    cout<<max<<endl;
            }
            
            else
            {
                q = 0;
            }
        }
        
        if(max == 2 || max == 3)
        {
            string s2 = "Three of a Kind";
            return s2;
        }
        else if(max == 1)
        {
            string s3 = "Pair";
            return s3;
        }
        else if(max == 0)
        {
            string s4 = "High Card";
            return s4;
        }
    return 0;
    }
};