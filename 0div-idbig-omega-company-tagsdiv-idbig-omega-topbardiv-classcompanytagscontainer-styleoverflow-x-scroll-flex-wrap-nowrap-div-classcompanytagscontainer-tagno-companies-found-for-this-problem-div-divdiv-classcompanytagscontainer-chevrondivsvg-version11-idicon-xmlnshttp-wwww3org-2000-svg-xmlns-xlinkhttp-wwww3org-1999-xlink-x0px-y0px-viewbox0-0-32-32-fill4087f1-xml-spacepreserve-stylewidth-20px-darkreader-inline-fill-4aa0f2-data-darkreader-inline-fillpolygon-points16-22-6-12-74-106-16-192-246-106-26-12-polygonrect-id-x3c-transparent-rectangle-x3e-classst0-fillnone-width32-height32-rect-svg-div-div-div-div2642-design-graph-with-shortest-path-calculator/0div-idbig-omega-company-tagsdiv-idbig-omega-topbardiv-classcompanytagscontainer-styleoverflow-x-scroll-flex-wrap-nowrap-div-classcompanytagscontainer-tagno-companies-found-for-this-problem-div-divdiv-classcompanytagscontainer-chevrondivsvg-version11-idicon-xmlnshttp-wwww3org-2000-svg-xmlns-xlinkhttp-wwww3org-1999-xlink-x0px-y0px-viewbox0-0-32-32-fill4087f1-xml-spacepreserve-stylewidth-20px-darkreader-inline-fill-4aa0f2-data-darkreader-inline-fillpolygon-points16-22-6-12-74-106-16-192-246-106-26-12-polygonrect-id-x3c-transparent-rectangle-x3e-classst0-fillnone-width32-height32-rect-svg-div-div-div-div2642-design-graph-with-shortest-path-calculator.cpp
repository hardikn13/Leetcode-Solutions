class Graph {
public:
    
    vector<vector<int>> gr;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        gr = vector<vector<int>>(n, vector<int>(n, 1e9));
        
        for(auto edge : edges)
            gr[edge[0]][edge[1]] = edge[2];
        
        for(int i = 0; i < n; i++)
            gr[i][i] = 0;
        
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    gr[i][j] = min(gr[i][k] + gr[k][j], gr[i][j]);
    }
    
    void addEdge(vector<int> edge) {
        for(int i = 0; i< n; i++)
            for(int j = 0; j < n; j++)
                gr[i][j] = min(gr[i][j], gr[i][edge[0]] + gr[edge[1]][j] + edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        if(gr[node1][node2] == 1e9)
            return -1;
        return gr[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */