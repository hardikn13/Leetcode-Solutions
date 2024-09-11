class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i = 0; i < 31; i++)
        {
            if(((1 << i) & start) != ((1 << i) & goal))
                ans++;
        }

        return ans;
    }
};