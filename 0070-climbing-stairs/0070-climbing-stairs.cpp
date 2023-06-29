class Solution {
public:
    int climbStairs(int n) {
        if(n < 3)
        {
            return n;
        }
        int prev = 2;
        int prev1 = 1;
        int curr;
        for(int i = 2; i < n; i++)
        {
            curr = prev + prev1;
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};