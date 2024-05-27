class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1)
            return -1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        int delRow[] = {-1, 1, 1, 0, -1, 0, 1, -1};
        int delCol[] = {0, -1, 0, 1, 1, -1, 1, -1};
        
        dist[0][0] = 0;
        q.push({1, {0, 0}});
        
        while(!q.empty())
        {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            if(r == n - 1 && c == m - 1)
                return d;
            
            for(int k = 0; k < 8; k++)
            {
                int nRow = r + delRow[k];
                int nCol = c + delCol[k];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 0
                  && (d + 1 < dist[nRow][nCol]))
                {
                    dist[nRow][nCol] = d + 1;
                    q.push({d + 1, {nRow, nCol}});
                }
            }
        }
        
        return -1;
    }
};