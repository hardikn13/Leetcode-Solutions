class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size() - 1; i++) {
            for (int j = 0; j < grid[0].size() - 1; j++) {
                int blackCount = 0;
                int whiteCount = 0;
                if (grid[i][j] == 'W') whiteCount++;
                if (grid[i][j] == 'B') blackCount++;
                if (grid[i + 1][j] == 'W') whiteCount++;
                if (grid[i + 1][j] == 'B') blackCount++;
                if (grid[i][j + 1] == 'W') whiteCount++;
                if (grid[i][j + 1] == 'B') blackCount++;
                if (grid[i + 1][j + 1] == 'W') whiteCount++;
                if (grid[i + 1][j + 1] == 'B') blackCount++;
                if (blackCount > 2 || whiteCount > 2) return true;
            }
        }
        return false;
    }
};
