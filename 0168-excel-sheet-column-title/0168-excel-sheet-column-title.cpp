class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        char tmp;
        while(columnNumber)
        {
            columnNumber -= 1;
            tmp = 'A' + columnNumber % 26;
            result = tmp + result;
            columnNumber /= 26;
        }
    return result;
    }
};