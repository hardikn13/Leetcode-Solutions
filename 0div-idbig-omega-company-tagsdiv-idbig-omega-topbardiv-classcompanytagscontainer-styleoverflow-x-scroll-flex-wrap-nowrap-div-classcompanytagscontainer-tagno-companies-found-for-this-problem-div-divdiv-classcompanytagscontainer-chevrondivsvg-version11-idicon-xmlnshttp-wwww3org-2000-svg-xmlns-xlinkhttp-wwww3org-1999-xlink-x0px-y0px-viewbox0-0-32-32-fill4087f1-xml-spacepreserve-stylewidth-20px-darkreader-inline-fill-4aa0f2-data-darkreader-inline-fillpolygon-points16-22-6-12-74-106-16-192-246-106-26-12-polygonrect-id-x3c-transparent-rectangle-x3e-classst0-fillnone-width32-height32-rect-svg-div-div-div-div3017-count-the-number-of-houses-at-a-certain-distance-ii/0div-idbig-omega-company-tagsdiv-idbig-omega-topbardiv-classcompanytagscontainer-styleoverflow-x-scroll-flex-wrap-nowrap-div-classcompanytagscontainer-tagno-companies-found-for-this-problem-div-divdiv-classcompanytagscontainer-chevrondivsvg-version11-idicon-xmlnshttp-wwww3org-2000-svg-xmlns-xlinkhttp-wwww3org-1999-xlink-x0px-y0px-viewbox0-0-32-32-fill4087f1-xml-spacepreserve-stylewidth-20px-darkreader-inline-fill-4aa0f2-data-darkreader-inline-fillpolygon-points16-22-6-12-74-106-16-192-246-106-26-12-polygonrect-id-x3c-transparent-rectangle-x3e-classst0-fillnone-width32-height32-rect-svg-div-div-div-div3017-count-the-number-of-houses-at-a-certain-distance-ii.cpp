class Solution {
public:
    vector<long long> lineAndCycle(long long n, long long lineLen, long long cycleLen)
    {
        vector<long long> res(n);

        for(int d = 1; d <= lineLen; d++)
        {
            long long mn = d + 1;
            long long mx = d + (cycleLen / 2);
            res[mn - 1] += 2;
            res[mx - 1] -= 2;
        }

        long long mn = cycleLen / 2 + 1;
        long long mx = cycleLen / 2 + lineLen;

        long long add = (cycleLen & 1 ? 2 : 1);

        res[mn - 1] += add;
        
        if(mx < n)
            res[mx] -= add;

        for(int i = 1; i < n; i++)
            res[i] += res[i - 1];

        for(int len = 1; len <= lineLen; len++)
            res[len - 1]++;

        return res;
    }

    vector<long long> lineAnswer(long long n, long long lineLen)
    {
        vector<long long> res(n);

        for(int len = 1, add = lineLen - 1; len < lineLen; len++, add--)
            res[len - 1] += add;

        return res;
    }

    vector<long long> cycleAnswer(long long n, long long cycleLen)
    {
        vector<long long> res(n);

        for(int len = 1; len < cycleLen / 2; len++)
            res[len - 1] += cycleLen;
        
        if(cycleLen % 2 == 1)
        {
            int len = cycleLen / 2;
            if (len - 1 >= 0)
                res[len - 1] += cycleLen;
        }
        else
        {
            int len = cycleLen / 2;
            if (len - 1 >= 0)
                res[len - 1] += (cycleLen / 2);  
        }

        return res;
    }

    vector<long long> twoLineAnswer(long long n, long long lineLen1, long long lineLen2,
                                    long long x, long long y)
    {
        vector<long long> res(n);

        if(lineLen1 > lineLen2)
            swap(lineLen1, lineLen2);
        
        long long plus = (x != y ? 1 : 0);
        
        for(int i = 0; i < lineLen1; i++)
        {
            long long mn = i + plus + 2;
            long long mx = i + plus + 1 + lineLen2;
            
            res[mn - 1]++;
            if(mx < n)
                res[mx]--;
        }

        for(int i = 1; i < n; i++)
            res[i] += res[i - 1];

        return res;
    }
    
    vector<long long> countOfPairs(int n, int x, int y) {
        
        vector<long long> ans(n);
        if(x > y)
            swap(x, y);
        
        long long lineLen1 = x - 1;
        long long lineLen2 = n - y;
        long long cycleLen = y - x + 1;
        long long finalLen = lineLen1 + lineLen2 + 2;
        
        auto line1ans = lineAnswer(n, lineLen1);
        auto line2ans = lineAnswer(n, lineLen2);
        auto cycleAns = cycleAnswer(n, cycleLen);       
        auto l1c = lineAndCycle(n, lineLen1, cycleLen);
        auto l2c = lineAndCycle(n, lineLen2, cycleLen);
        auto l1l2 = twoLineAnswer(n, lineLen1, lineLen2, x, y);
        
        for(int i = 0; i < n; i++)
        {
            ans[i] += line1ans[i];
            ans[i] += line2ans[i];
            ans[i] += cycleAns[i];
            ans[i] += l1c[i];
            ans[i] += l2c[i];
            ans[i] += l1l2[i];
            ans[i] *= 2;
        }

        return ans;
    }
};