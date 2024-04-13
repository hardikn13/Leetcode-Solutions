class Solution {  
private:
    
    vector<int> nextSmallerElement(vector<int> arr, int n)
        {
            stack<int> stk;
            stk.push(-1);
            vector<int> ans(n);
            for(int i = n-1; i >= 0; i--)
            {
                while(stk.top() != -1 && arr[stk.top()] >= arr[i])
                {
                    stk.pop();
                }
                ans[i] = stk.top();
                stk.push(i);
            }
            return ans;
        }
    
    vector<int> prevSmallerElement(vector<int> arr, int n)
        {
            stack<int> stk;
            stk.push(-1);
            vector<int> ans(n);
            for(int i = 0; i < n; i++)
            {
                while(stk.top() != -1 && arr[stk.top()] >= arr[i])
                {
                    stk.pop();
                }
                ans[i] = stk.top();
                stk.push(i);
            }
            return ans;
        }
    
    int largestRectangleArea(vector<int> heights, int n) {
        int max = 0;
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        for(int i = 0; i < n; i++)
        {
            int l = heights[i];
            if(next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            if(area > max)
            {
                max = area;
            }
        }
        return max;
    }
    
    
    public:
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        cout<<matrix[0][0]<<endl;
        
        vector<int> v(m);
        for(int i = 0; i < m; i++){
            int a = int(matrix[0][i] - '0');
            v[i] = a;
        }
        int area = largestRectangleArea(v,m);

        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] != '0'){
                    v[j] += int(matrix[i][j] - '0'); 
                }
                else{
                    v[j] = 0;
                } 
            }
            area = max(area, largestRectangleArea(v, m));
        }
        return area;
    }
};