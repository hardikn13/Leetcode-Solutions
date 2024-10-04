class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long sum = 0;
        unordered_map<long, long> mp;
        for(int i = 0; i < n; i++)
        {
            sum += skill[i];
            mp[skill[i]]++;
        }

        long long k = 2 * sum / n;
        long long ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(mp.find(k - skill[i]) == mp.end())
                return -1;

            ans += (skill[i]) * (k - skill[i]);
            mp[k - skill[i]]--;
            if(mp[k - skill[i]] == 0)
                mp.erase(k - skill[i]);
        }

        return ans / 2;
    }
};