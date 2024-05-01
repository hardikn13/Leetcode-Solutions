class Solution {
public:
    
    int countBits(int num)
    {
        int cnt = 0;
        while(num > 0)
        {
            num = (num & (num - 1));
            cnt++;
        }
        
        return cnt;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda = [&] (int &a, int &b)
        {
            int bitsInA = countBits(a);
            int bitsInB = countBits(b);

            if(bitsInA == bitsInB)
                return a < b;
            else
                return bitsInA < bitsInB;
        };
        
        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};