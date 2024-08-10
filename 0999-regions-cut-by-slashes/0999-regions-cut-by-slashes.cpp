class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &ans)
    {
        int n = ans.size();
        int m = ans[0].size();
        vis[row][col] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol]
            && ans[nRow][nCol] == 0)
            {
                dfs(nRow, nCol, vis, ans);
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n * 3, vector<int>(m * 3, 0));
        vector<vector<int>> vis = ans;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '/')
                {
                    ans[i * 3][j * 3 + 2] = 1;
                    ans[i * 3 + 1][j * 3 + 1] = 1;
                    ans[i * 3 + 2][j * 3] = 1;
                }
                else if(grid[i][j] == '\\')
                {
                    ans[i * 3][j * 3] = 1;
                    ans[i * 3 + 1][j * 3 + 1] = 1;
                    ans[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n * 3; i++)
        {
            for(int j = 0; j < m * 3; j++)
            {
                if(!vis[i][j] && ans[i][j] == 0)
                {
                    dfs(i, j, vis, ans);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};