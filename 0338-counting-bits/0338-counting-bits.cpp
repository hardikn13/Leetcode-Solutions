class Solution {
public:
    
    int decToBinary(int z)
    {
        int cnt = 0;
        for(int i = 31; i >= 0; i--)
        {
            int k = z >> i;
            if (k & 1)
                cnt++;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i <= n; i++)
        {
            ans[i] = decToBinary(i);
        }
        return ans;
    }
};