class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (!isalnum(c)) {
                return false;
            }
            if (isalpha(c)) {
                if (vowels.count(tolower(c)) > 0) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
            }
        }
        }

        return hasVowel && hasConsonant;
    }
};