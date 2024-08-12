#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int sz = str.size();

        int i = sz - 2;
        while(i >= 0 && str[i] >= str[i + 1])
            i--;

        if(i < 0)
            return -1;

        int j = sz - 1;
        while(str[j] <= str[i])
            j--;

        swap(str[i], str[j]);
        reverse(str.begin() + i + 1, str.end());

        long long result = stoll(str);
        if(result > INT_MAX)
            return -1;

        return (int)result;
    }
};
