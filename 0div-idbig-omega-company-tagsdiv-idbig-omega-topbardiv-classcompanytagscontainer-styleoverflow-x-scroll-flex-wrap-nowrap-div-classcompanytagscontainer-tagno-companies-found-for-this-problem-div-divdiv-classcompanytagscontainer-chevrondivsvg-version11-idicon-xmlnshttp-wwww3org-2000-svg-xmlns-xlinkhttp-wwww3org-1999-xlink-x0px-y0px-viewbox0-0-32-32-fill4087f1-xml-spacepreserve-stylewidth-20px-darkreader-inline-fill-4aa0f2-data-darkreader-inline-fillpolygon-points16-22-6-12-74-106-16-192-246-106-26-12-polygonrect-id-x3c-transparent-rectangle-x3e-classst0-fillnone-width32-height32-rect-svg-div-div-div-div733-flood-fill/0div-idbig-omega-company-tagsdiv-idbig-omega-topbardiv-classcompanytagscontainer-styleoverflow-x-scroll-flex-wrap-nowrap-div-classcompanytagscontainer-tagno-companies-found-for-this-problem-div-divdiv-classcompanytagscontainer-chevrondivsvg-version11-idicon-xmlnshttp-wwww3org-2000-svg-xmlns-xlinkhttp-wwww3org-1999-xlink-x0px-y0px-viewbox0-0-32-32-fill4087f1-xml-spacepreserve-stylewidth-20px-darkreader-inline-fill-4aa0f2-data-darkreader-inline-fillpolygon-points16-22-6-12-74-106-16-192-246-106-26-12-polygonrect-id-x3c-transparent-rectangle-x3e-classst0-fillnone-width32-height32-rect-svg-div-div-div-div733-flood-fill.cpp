class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vis = image;
        queue<pair<int, int>> q;
        int t = image[sr][sc];
        
        vis[sr][sc] = color;
        q.push({sr, sc});
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            
            for(int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] !=
                   color && image[nRow][nCol] == t)
                {
                    vis[nRow][nCol] = color;
                    q.push({nRow, nCol});
                }
            }
            
        }
        
        return vis;
    }
};