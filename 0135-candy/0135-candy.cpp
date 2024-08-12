class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1, sum = 1;
        int peak, down;

        while(i < n)
        {
            if(ratings[i] == ratings[i-1])
            {
                sum += 1;
                i++;
                continue;
            }
            
            peak = 1;
            while(i < n && ratings[i] > ratings[i-1])
            {
                peak++;
                sum += peak;
                i++;
            }

            down = 1;
            while(i < n && ratings[i] < ratings[i-1])
            {
                sum += down;
                i++;
                down++;
            }

            if(down > peak)
                sum += down - peak;
        }
        
        return sum;
    }
};