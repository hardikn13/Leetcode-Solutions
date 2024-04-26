#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> largerLeft(n, 0);
        
        stack<int> st;
        st.push(-1);
        
        for(int i = 0; i < n; i++)
        {
            int id = st.top();
            while(id != -1 && nums[id] <= nums[i])
            {
                st.pop();
                id = st.top();
            }
            
            st.push(i);
            largerLeft[i] = id;
        }
        
        long long ans = 0;
        unordered_map<int, ordered_set> mp;
        
        for(int i = 0; i < n; i++)
        {
            int ele = nums[i];
            int nearestLargest = largerLeft[i];
            int cnt = mp[ele].size() - mp[ele].order_of_key(nearestLargest);
            ans += cnt + 1;
            
            mp[ele].insert(i);
        }
        
        return ans;
    }
};