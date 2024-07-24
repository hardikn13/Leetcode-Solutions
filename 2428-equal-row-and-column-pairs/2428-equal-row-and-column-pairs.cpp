class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            vector<int> row;
            for(int j = 0; j < n; j++)
            {
                row.push_back(grid[i][j]);
            }

            for(int j = 0; j < n; j++)
            {
                vector<int> col;
                for(int k = 0; k < n; k++)
                {
                    col.push_back(grid[k][j]);
                }
                
                if(row == col)
                    ans++;
            }
        }

        return ans;
    }
};