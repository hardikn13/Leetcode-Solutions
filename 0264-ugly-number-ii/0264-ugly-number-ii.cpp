class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> v(n + 1);
        v[1] = 1;
        
        int a = 1, b = 1, c = 1;
        for(int i = 2; i <= n; i++)
        {
            int n1 = 2 * v[a];
            int n2 = 3 * v[b];
            int n3 = 5 * v[c];
            
            v[i] = min(n1, min(n2, n3));
            if(v[i] == n1)
                a++;
            if(v[i] == n2)
                b++;
            if(v[i] == n3)
                c++;
        }
        
        return v[n];
    }
};