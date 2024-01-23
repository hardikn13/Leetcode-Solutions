class Solution {
public:
    bool compare(string s, vector<int> hash)
    {
        vector<int> check(26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            if(check[s[i] - 'a'] == 1)
                return false;
            check[s[i] - 'a'] = 1;
        }
        
        for(int i = 0; i < s.size(); i++)
            if(hash[s[i] - 'a'] == 1)
                return false;
        
        return true;
    }
    
    int f(int ind, vector<int> &hash, vector<string>& arr, int len)
    {
        if(ind == arr.size())
            return len;
        
        if(compare(arr[ind], hash) == false)
            return f(ind + 1, hash, arr, len);
        else
        {
            for(int i = 0; i < arr[ind].size(); i++)
                hash[arr[ind][i] - 'a'] = 1;
            len += arr[ind].size();
            int p1 = f(ind + 1, hash, arr, len);
            
            for(int i = 0; i < arr[ind].size(); i++)
                hash[arr[ind][i] - 'a'] = 0;
            len -= arr[ind].size();
            int p2 = f(ind + 1, hash, arr, len);
            
            return max(p1, p2);
        }
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> hash(26, 0);
        return f(0, hash, arr, 0);
    }
};