class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int delRow[], int delCol[], int ini)
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        for(int i = 0; i <  4; i++)
        {
            int nRow = row +delRow[i];
            int nCol = col + delCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == ini && ans[nRow][nCol] != newColor)
            {
                dfs(nRow, nCol, ans, image, newColor, delRow, delCol, ini);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        dfs(sr, sc, ans, image, color, delRow, delCol, ini);
        
        return ans;
    }
};