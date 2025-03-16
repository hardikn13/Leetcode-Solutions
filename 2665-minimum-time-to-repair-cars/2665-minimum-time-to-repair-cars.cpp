class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0;
        long long high = 1e14;
        while(low < high)
        {
            long long mid = low + (high - low) / 2;

            long long repaired = 0;
            for(auto &it : ranks)
                repaired += sqrt(mid / it);

            if(repaired < cars)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};