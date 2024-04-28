class Solution {
public:
    int N;
    vector<int> ans, count;
    vector<vector<int>> gr;

    void dfs(int node, int par){
        for(auto child : gr[node]){
            if(child != par){
                dfs(child, node);// while coming back after dfs traversal
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfs2(int node, int par){
        for(auto child : gr[node]){
            if(child != par){
                ans[child] = ans[node] - count[child] + (N - count[child]);// upar wale dfs se sirf 
                //root ka correct araha ,for child nodes need this calculation 
                dfs2(child, node);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        gr = vector<vector<int>>(n);
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        ans = vector<int>(n, 0);
        count = vector<int>(n, 1);

        dfs(0, -1);
        dfs2(0, -1);

        return ans;
    }
};