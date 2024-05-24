class Solution {
public:
    void f(int ind, int currScore, int &ans, vector<string>& words, unordered_map<char, int> &l, vector<int>& score) {
        if(ind == words.size())
        {
            ans = max(ans, currScore);
            return;
        }

        f(ind + 1, currScore, ans, words, l, score);
        
        bool canInclude = true;
        int wordScore = 0;
        unordered_map<char, int> temp = l;

        for(auto ch : words[ind])
        {
            if(temp[ch] > 0)
            {
                temp[ch]--;
                wordScore += score[ch - 'a'];
            }
            else
            {
                canInclude = false;
                break;
            }
        }

        if(canInclude)
            f(ind + 1, currScore + wordScore, ans, words, temp, score);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> l;
        for(auto it : letters)
            l[it]++;
        
        int ans = 0;
        f(0, 0, ans, words, l, score);
        return ans;
    }
};
