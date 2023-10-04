class Solution {
public:
    
    int countOnes(vector<int>& row) {
        int count = 0;
        for (int num : row) {
            if (num == 1)
                count++;
        }
        return count;
    }
    
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        int cnt_max = 0;
        int index = 0;
        
        for(int i = 0; i < n; i++)
        {
            int cnt_ones = countOnes(mat[i]);
            
            if(cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        
        
        return {index, cnt_max};
    }
};