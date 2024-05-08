class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;
        vector<string> ans(score.size());
        sort(sorted.begin(), sorted.end(), greater<int>());
        
        unordered_map<int, int> index;
        for(int i = 0; i < score.size(); i++)
            index[score[i]] = i;

        for(int i = 0; i < score.size(); i++)
        {
            if(i == 0)
                ans[index[sorted[i]]] = "Gold Medal";
            else if(i == 1)
                ans[index[sorted[i]]] = "Silver Medal";
            else if(i == 2)
                ans[index[sorted[i]]] = "Bronze Medal";
            else
                ans[index[sorted[i]]] = to_string(i + 1);
        }
        
        return ans;
    }
};
