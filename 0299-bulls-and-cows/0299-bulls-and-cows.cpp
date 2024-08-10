class Solution {
public:
    string getHint(string secret, string guess) {
        int right = 0, wrong = 0;
        vector<int> hash(10, 0), sup(10, 0);
        for(int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i])
                right++;
            else
            {
                hash[guess[i] - '0']++;
                sup[secret[i] - '0']++;
            }
        }

        for(int i = 0; i < 10; i++)
            wrong += min(hash[i], sup[i]);

        string ans = to_string(right) + 'A' + to_string(wrong) + 'B';
        return ans;
    }
};