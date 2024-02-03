class Solution {
public:
    long long flowerGame(int n, int m) {
        long long t = (long long)n * (long long)m;
        if(t > 1)
            return t / 2;
        return 0;
    }
};