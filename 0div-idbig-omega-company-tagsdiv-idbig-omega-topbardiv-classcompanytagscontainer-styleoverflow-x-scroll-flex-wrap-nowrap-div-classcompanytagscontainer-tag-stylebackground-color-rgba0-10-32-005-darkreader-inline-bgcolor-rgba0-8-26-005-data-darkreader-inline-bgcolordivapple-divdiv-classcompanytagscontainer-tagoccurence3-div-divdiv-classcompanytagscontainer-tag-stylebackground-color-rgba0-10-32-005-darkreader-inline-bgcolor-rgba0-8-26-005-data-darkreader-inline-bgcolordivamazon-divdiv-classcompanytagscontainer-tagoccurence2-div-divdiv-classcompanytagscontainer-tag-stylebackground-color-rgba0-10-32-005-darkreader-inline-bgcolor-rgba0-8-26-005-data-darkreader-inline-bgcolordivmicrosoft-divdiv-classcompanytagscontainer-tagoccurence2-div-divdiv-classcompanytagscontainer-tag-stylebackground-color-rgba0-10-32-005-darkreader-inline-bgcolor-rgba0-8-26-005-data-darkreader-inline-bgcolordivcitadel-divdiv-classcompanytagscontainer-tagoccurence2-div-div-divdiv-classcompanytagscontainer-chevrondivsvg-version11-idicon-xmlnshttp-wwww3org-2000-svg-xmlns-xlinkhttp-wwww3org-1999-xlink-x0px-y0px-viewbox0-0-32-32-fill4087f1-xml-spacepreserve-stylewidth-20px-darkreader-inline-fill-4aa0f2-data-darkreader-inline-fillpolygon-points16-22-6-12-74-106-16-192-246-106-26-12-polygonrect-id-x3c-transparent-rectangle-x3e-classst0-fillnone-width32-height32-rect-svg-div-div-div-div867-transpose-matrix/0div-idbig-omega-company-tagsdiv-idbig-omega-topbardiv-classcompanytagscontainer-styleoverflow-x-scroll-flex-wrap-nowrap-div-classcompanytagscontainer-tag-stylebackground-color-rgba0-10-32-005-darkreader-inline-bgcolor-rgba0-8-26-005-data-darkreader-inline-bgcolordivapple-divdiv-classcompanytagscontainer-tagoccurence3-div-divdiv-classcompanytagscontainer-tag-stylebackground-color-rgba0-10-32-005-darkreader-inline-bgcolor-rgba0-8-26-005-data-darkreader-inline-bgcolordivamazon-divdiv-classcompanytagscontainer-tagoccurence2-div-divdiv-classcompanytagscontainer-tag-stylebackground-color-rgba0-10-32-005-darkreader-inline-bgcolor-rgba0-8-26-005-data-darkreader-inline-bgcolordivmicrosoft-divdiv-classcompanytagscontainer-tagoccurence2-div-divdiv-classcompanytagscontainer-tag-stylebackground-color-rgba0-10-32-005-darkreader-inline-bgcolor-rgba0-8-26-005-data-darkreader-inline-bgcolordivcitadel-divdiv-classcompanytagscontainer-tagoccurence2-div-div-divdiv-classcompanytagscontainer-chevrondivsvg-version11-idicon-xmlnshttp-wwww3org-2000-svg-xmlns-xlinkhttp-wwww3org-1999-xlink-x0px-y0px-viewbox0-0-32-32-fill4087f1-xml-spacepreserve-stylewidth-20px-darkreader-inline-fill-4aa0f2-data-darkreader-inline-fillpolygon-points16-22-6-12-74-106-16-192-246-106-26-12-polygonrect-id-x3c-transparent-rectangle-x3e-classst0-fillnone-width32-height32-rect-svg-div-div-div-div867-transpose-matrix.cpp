class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> t(m, vector<int>(n, 0));
        
        int a = 0, b = 0;
        for(int i = 0; i < n; i++)
        {
            b = 0;
            for(int j = 0; j < m; j++)
            {
                t[b++][a] = matrix[i][j];
            }
            a++;
        }
        
        return t;
    }
};