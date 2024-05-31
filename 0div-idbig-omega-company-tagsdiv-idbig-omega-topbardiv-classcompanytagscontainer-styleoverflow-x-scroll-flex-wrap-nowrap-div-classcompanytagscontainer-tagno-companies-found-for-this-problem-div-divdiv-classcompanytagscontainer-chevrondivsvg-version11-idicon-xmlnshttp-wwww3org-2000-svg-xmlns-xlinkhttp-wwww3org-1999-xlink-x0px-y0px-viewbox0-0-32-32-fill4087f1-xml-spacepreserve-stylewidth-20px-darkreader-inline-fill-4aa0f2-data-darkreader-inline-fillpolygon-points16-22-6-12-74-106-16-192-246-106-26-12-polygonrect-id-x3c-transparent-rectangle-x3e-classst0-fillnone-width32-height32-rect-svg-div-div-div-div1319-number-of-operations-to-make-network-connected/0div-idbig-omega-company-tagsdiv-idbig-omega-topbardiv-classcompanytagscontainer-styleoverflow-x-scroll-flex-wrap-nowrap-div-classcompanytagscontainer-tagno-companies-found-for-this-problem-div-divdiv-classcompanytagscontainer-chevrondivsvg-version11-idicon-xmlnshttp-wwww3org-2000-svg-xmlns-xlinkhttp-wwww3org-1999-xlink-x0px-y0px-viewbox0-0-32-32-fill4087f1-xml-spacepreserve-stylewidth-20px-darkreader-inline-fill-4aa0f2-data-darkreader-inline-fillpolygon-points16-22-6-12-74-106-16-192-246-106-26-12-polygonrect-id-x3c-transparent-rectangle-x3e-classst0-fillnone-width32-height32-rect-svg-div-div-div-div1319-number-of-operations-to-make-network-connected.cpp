class DisjointSet
{
    vector<int> rank, parent, size;
    
    public:
    
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);
        
        int extra = 0;
        for(auto it : connections)
        {
            if(ds.findUPar(it[0]) != ds.findUPar(it[1]))
                ds.unionBySize(it[0], it[1]);
            else
                extra++;
        }
        
        int connect = 0;
        for(int i = 0; i < n; i++)
            if(ds.findUPar(i) == i)
                connect++;
        
        int ans = connect - 1;
        if(extra >= ans)
            return ans;
        
        return -1;
    }
};