class Solution {
public:
    string getResult(string &words,  unordered_set<string> &st){
        
        for(int i = 0; i < words.size(); i++)
        {
            string curr = words.substr(0,i);

            if(st.count(curr))
                return curr;    
        }

        return words;
        
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);

        string words;
        string ans;

        while(getline(ss,words,' '))
            ans += getResult(words,st) + " ";

        ans.pop_back();
        return ans;
    }
};