class Solution {
public:
    int minStoneSum(std::vector<int>& piles, int k) {
        
        priority_queue<int> pq(piles.begin(), piles.end());
        
        while (k--)
        {
            int maxPile = pq.top();
            pq.pop();
            maxPile -= floor(maxPile / 2.0);
            pq.push(maxPile);
        }
        
        int total = 0;
        while (!pq.empty())
        {
            total += pq.top();
            pq.pop();
        }
        
        return total;
    }
};
