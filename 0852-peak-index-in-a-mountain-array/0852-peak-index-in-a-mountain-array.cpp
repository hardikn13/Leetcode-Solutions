class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int max=-999999,h=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
                h=i;
            }
        }
        return h;
    }
};