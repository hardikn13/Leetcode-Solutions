class Solution {
public:
    bool f(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int n = grid1.size();
        int m = grid1[0].size();
        vis[row][col] = 1;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        bool ans = true;
        for(int i = 0; i < 4; i++)
        {
            int nRow = delRow[i] + row;
            int nCol = delCol[i] + col;

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] &&
             grid2[nRow][nCol] == 1)
            {
                if(grid1[nRow][nCol] == 0)
                    ans = false;

                ans &= f(nRow, nCol, vis, grid1, grid2);
            }
        }

        return ans;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid2[i][j] == 1)
                {
                    if(grid1[i][j] == 0)
                        continue;

                    if(f(i, j, vis, grid1, grid2))
                        ans++;
                }
            }
        }

        return ans;
    }
};