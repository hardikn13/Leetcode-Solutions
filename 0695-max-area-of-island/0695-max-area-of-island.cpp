class DisjointSet
{
    public:
    
    vector<int> rank, parent, size;
    
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v)
        {
            return;
        }
        
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v)
        {
            return;
        }
        
        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n * m);
        bool flag = false;
        
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(grid[row][col] == 0)
                {
                    continue;
                }
                
                int delRow[] = {-1, 0, 1, 0};
                int delCol[] = {0, 1, 0, -1};
                flag = true;
            
                for(int i = 0; i < 4; i++)
                {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];
                
                    if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0 && grid[nRow][nCol] == 1)
                    {
                        int nodeNo = row * m + col;
                        int nNodeNo = nRow * m + nCol;
                        ds.unionBySize(nodeNo, nNodeNo);
                    }
                }
            }
        }
        
        int mx = 0;
        for(int cellNo = 0; cellNo < n * m; cellNo++)
        {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        
        if(mx == 1 && flag == false)
        {
            return 0;
        }
        
        return mx;
    }
};