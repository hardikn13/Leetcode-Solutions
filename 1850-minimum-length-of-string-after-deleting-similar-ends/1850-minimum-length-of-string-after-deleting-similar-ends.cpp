class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        int ans = n;

        while(i < j)
        {
            if(s[i] != s[j])
                break;

            char c = s[i];
            while(s[i] == c && i < j)
            {
                i++;
                ans--;
            }

            while(s[j] == c && i <= j)
            {
                j--;
                ans--;
            }

            cout<<i<<j<<ans<<endl;
        }

        return ans;
    }
};