class Solution {
public:
    int countDigits(int num) {
        char strc[10];
    sprintf(strc, "%d", num);

    int count = 0;
    for (int i = 0; i < strlen(strc); i++) {
        int digit = strc[i] - '0';
        if (digit != 0 && num % digit == 0) {
            count++;
        }
    }
    return count;
    }
};