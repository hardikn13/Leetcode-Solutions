class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> hm;
        for(int i=0;i<tasks.size();i++){
            hm[tasks[i]]++;
        }
        int count=0,freq=0;
        for(auto i:hm)
        {
            freq=i.second;
            if(freq==1)
            {
                return -1;
            }
            if(freq % 3 == 0)
            {
                count += freq / 3;
            }
            else if(freq % 3 == 2)
            {
                count += freq / 3;
                count++;
            }
            else
            {
                count += freq / 3;
                count++;
            }
        }
        return count;
    }
};