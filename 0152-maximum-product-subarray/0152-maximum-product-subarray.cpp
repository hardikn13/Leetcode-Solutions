class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long pref = 1, suff = 1;
        long long maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(pref == 1000000000 || suff == 1000000000)
                break;

            if(pref == 0)
                pref = 1;
            if(suff == 0)
                suff = 1;

            pref *= nums[i];
            suff *= nums[n - i - 1];

            maxi = max(maxi, max(pref, suff));
        }

        return (int)maxi;
    }
};