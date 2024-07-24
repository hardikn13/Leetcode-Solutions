class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int del = 0;
        int i = 0, j = 0;
        int len = 0, ans = 0;
        bool t = false;
        while(j < n)
        {
            if(nums[j] == 1)
            {
                len++;
            }
            else
            {
                if(del == 0)
                {
                    t = true;
                    del = 1;
                }
                else
                {
                    while(del)
                    {
                        if(nums[i] == 1)
                        {
                            i++;
                            len--;
                        }
                        else
                        {
                            i++;
                            del--;
                        }
                    }
                    del = 1;
                }
            }
            ans = max(ans, len);
            j++;
        }

        if(t == false)
            return ans - 1;
        
        return ans;
    }
};