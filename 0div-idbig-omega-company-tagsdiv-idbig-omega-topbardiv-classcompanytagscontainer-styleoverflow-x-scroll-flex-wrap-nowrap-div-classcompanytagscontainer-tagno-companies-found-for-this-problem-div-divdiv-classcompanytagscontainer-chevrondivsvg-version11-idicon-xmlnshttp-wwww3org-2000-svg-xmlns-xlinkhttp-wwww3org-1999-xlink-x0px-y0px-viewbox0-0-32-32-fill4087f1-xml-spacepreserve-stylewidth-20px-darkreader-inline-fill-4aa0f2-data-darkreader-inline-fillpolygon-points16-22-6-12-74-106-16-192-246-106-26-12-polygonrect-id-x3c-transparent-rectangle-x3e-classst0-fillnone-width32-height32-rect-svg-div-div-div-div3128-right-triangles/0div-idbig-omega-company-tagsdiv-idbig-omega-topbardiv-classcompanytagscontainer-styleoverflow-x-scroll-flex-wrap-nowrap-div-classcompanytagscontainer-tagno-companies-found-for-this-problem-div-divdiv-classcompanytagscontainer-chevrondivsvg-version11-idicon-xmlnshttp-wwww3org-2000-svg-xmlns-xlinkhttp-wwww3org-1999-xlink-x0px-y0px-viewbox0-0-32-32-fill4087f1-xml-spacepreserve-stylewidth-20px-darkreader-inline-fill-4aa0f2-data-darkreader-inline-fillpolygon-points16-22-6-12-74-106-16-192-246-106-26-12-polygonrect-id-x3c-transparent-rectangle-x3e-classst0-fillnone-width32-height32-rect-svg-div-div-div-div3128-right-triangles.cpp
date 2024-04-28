class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> row(n);
        vector<int> col(m);
        
        for(int i = 0; i < n; i++)
            row[i] = count(grid[i].begin(), grid[i].end(), 1);
        
        for(int j = 0; j < m; j++)
        {
            int c = 0;
            for(int i = 0; i < n; i++)
            {
                if(grid[i][j])
                    c++;
            }
            
            col[j] = c;
        }
        
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            int oneR = 0;
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]) 
                { 
                    ans += ((col[j] - 1) * (row[i] - 1));
                     
                } 
            }
        }
        
        return ans;
    }
};