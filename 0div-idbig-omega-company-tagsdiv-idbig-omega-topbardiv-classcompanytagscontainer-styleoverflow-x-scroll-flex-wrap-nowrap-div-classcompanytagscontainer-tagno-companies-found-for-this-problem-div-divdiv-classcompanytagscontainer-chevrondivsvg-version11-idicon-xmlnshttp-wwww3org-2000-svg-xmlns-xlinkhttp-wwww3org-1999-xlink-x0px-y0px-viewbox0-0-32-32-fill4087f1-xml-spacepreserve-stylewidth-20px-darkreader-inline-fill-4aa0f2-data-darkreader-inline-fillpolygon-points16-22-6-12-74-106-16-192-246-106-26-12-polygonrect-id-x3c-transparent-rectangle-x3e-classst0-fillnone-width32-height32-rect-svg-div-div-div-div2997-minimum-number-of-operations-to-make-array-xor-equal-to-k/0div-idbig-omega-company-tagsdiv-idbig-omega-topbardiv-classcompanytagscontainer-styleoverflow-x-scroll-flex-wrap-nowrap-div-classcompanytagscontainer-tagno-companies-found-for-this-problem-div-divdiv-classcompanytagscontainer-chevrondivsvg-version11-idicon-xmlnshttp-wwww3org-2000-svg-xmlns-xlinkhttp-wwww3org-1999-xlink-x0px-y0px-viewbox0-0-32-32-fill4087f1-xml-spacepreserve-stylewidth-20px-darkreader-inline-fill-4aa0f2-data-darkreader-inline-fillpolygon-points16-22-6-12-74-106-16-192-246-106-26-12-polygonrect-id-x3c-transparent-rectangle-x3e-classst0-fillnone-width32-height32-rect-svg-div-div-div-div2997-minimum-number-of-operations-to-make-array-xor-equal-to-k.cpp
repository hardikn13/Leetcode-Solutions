class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        int x = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            x ^= nums[i];
        }
        
        bitset<sizeof(int) * 8> bit1(x);
        bitset<sizeof(int) * 8> bit2(k);
        
        int cnt = 0;
        for(int i = 0; i < bit1.size(); i++)
        {
            if(bit1[i] != bit2[i])
                cnt++;
        }
        
        return cnt;
    }
};