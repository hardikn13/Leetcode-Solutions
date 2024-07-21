class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int n = target.size();
        int ans = 0, prev = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || target[i] > prev)
                ans += target[i] - prev;

            prev = target[i];
        }

        return ans;
    }
};