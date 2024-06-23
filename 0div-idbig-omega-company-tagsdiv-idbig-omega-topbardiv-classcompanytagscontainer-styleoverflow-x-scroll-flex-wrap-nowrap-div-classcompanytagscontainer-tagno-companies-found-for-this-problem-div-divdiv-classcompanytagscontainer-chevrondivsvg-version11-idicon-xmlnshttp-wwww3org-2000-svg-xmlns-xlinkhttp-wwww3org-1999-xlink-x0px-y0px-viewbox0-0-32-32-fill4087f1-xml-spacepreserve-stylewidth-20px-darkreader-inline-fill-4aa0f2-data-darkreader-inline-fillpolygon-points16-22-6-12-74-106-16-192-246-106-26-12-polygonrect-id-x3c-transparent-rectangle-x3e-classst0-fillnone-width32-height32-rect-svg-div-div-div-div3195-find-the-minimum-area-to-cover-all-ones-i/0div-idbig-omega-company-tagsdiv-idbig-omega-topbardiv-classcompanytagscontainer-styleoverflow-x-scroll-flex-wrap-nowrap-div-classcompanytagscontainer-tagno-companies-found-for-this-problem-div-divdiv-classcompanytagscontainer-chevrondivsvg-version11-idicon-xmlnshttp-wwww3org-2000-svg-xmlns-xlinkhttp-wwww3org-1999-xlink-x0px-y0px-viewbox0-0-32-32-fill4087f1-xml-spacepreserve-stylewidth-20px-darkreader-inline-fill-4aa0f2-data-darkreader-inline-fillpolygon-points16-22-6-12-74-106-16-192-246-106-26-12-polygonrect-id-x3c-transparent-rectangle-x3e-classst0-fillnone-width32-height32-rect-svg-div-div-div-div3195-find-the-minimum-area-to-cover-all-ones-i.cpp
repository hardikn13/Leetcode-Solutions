class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int lowx = INT_MAX, lowy = INT_MAX, highx = INT_MIN, highy = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    lowx = min(lowx, i);
                    lowy = min(lowy, j);
                    highx = max(highx, i);
                    highy = max(highy, j);
                }
            }
        }
        
        return (highx - lowx + 1) * (highy - lowy + 1);
    }
};