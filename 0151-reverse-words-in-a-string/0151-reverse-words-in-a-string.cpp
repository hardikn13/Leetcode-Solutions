class Solution {
public:
    string reverseWords(string s) {
std::string str = "";

    int end = s.size() - 1;
    while (end >= 0)
    {
        // Find the index of the first non-space character from the end of the string.
        while (end >= 0 && s[end] == ' ')
        {
            end--;
        }

        if (end < 0)
        {
            // There are no more words to reverse.
            break;
        }

        // Find the index of the first space character from the end of the string.
        int start = end;
        while (start >= 0 && s[start] != ' ')
        {
            start--;
        }

        // Append the reversed word to the result string.
        for (int i = start + 1; i <= end; i++)
        {
            str += s[i];
        }

        str += ' ';

        end = start;
    }

    // Trim any extra space characters from the end of the result string.
    while (!str.empty() && str.back() == ' ')
    {
        str.pop_back();
    }

    return str;
    }
};