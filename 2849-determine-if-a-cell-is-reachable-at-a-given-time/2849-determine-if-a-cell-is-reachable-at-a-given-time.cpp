class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int x = abs(fx - sx);
        int y = abs(fy - sy);
        int g = max(x, y);
        if(g > t or (g == 0 and (t < 2 and t > 0)))
            return false;
        else
            return true;
    }
};