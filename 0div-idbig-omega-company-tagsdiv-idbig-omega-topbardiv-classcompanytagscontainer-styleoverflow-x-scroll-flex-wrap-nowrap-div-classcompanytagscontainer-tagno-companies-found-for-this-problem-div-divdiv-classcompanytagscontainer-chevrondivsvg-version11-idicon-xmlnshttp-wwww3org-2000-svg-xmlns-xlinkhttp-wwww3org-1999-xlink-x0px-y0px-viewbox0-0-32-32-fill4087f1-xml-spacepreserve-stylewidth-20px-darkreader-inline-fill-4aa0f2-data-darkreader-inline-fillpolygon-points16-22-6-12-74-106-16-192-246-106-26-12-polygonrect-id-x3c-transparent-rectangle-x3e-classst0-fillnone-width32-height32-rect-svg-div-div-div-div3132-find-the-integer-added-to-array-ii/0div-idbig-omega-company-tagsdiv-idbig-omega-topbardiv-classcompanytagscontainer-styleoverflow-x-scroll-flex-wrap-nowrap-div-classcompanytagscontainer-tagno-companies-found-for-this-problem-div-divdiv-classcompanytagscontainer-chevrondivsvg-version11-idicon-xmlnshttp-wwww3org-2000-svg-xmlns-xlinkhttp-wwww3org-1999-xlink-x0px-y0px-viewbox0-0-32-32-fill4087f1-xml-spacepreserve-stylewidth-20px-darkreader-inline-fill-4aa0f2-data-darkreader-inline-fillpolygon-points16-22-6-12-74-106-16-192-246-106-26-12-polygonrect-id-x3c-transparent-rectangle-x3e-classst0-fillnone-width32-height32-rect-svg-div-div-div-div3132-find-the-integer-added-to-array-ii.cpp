class Solution {
public:
    bool f(vector<int>& v, vector<int>& nums2)
    {
        int i = 0, j = 0, skip = 2;
        sort(nums2.begin(), nums2.end());
        while(i < v.size() && j < nums2.size())
        {
            if(v[i] == nums2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
                skip--;
                if(skip < 0)
                    return false;
            }
        }
        
        return j == nums2.size() && (i - j) <= 2;
    }
    
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                mp[nums2[j] - nums1[i]]++;
            }
        }

        for(auto it : mp) {
            
            vector<int> v(nums1.size());
            for(int i = 0; i < nums1.size(); i++)
                v[i] = nums1[i] + it.first;
            
            sort(v.begin(), v.end());

            if(f(v, nums2))
                ans = min(ans, it.first);
                
        }
        return ans;
    }
};
