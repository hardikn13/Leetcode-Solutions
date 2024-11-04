class Solution {
public:
    string compressedString(string word) {
        
        string s = "";
        if(word.empty())
            return s;

        char c = word[0];
        int count = 1;

        for (int i = 1; i < word.size(); ++i)
        {
            if (word[i] == c && count < 9) {
                count++;
            } else {
                s += to_string(count) + c;
                c = word[i];
                count = 1;
            }
        }

        s += to_string(count) + c;

        return s;
    }
};