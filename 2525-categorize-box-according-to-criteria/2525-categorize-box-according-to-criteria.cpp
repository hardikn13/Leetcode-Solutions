class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        string s="";
        
        if((length>=10000||width>=10000||height>=10000||mass>=10000||(long long)length * width * height >= 1000000000)&&mass>=100)
        {
            s.append("Both");
        }
        else if((length>=10000||width>=10000||height>=10000||mass>=10000||(long long)length * width * height >= 1000000000)&&mass<100)
        {
            s.append("Bulky");
        }
        else if(mass>=100)
        {
            s.append("Heavy");
        }
        else
        {
            s.append("Neither");
        }
        return s;
    }
};