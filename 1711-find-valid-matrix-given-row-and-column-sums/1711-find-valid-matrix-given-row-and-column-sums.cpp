class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        
        int n = row.size();
        int m = col.size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(row[i] < col[j])
                {
                    ans[i][j] = row[i];
                    col[j] -= row[i];
                    row[i] = 0;
                }
                else
                {
                    ans[i][j] = col[j];
                    row[i] -= col[j];
                    col[j] = 0;
                }
            }
        }

        return ans;
    }
};