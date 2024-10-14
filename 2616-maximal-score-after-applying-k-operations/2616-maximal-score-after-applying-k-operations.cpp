class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        long long score = 0;
        priority_queue<int> pq;
        for(auto it : nums)
            pq.push(it);
        
        int i = 0;
        while(i < k)
        {
            int ele = pq.top();
            pq.pop();
            
            score += ele;
            pq.push(ceil(ele / 3.0));
            i++;
        }
        
        return score;
    }
};