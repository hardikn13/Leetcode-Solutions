class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue <long long, vector<long long>, greater<long long>> pq;
        
        for(int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }
        
        long long count = 0, i = 0, l = 0;
        while(!pq.empty())
        {
            if(pq.top() >= k)
                break;
            
            if(i % 2 == 0)
            {
                l = pq.top();
                pq.pop();
                count++;
            }
            else
            {
                long long z = (min(pq.top(), l) * 2) + max(pq.top(), l);
                pq.pop();
                pq.push(z);
            }
            
            i++;
        }
        
        return (int)count;
    }
};