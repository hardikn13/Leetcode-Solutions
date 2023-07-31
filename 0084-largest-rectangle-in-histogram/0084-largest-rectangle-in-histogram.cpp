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
    
    
    public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), max = 0;
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
};