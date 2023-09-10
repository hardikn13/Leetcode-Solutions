class Solution {
public:
    

    int f(int i, vector<pair<int, int>> &extraSource, vector<pair<int, int>> &zeroes, map<pair<int, int>, bool> &visited)
    {
        if(i == extraSource.size())
            return 0;
        
        int mini = INT_MAX;
        for(auto it : zeroes)
        {
            if(!visited[it])
            {
                visited[it] = true;
                int curr = abs(extraSource[i].first - it.first) + abs(extraSource[i].second - it.second) + f(i + 1, extraSource, zeroes, visited);
                mini = min(mini, curr);
                visited[it] = false;
            }
        }
        return mini;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        
        vector<pair<int, int>> extraSource;
        vector<pair<int, int>> zeroes;
        map<pair<int, int>, bool> visited;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0)
                    zeroes.push_back({i, j});
                else
                {
                    int extra = grid[i][j] - 1;
                    while(extra)
                    {
                        extraSource.push_back({i, j});
                        extra--;
                    }
                }
                
            }
        }
        
        return f(0, extraSource, zeroes, visited);
    }
};