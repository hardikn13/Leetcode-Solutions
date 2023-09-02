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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 0)
                {
                    continue;
                }
                
                int delRow[] = {-1, 0, 1, 0};
                int delCol[] = {0, 1, 0, -1};
            
                for(int i = 0; i < 4; i++)
                {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];
                
                    if(nRow < n && nRow >= 0 && nCol < n && nCol >= 0 && grid[nRow][nCol] == 1)
                    {
                        int nodeNo = row * n + col;
                        int nNodeNo = nRow * n + nCol;
                        ds.unionBySize(nodeNo, nNodeNo);
                    }
                }
            }
        }
        
        int mx = 0;
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 1)
                {
                    continue;
                }
                
                int delRow[] = {-1, 0, 1, 0};
                int delCol[] = {0, 1, 0, -1};
                set<int> components;
            
                for(int i = 0; i < 4; i++)
                {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];
                
                    if(nRow < n && nRow >= 0 && nCol < n && nCol >= 0)
                    {
                        if(grid[nRow][nCol] == 1)
                        {
                            components.insert(ds.findUPar(nRow * n + nCol));
                        }
                    }
                }
                
                int sizeTotal = 1;
                for(auto it : components)
                {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal);
            }
        }
        
        for(int cellNo = 0; cellNo < n * n; cellNo++)
        {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        
        return mx;
    }
};