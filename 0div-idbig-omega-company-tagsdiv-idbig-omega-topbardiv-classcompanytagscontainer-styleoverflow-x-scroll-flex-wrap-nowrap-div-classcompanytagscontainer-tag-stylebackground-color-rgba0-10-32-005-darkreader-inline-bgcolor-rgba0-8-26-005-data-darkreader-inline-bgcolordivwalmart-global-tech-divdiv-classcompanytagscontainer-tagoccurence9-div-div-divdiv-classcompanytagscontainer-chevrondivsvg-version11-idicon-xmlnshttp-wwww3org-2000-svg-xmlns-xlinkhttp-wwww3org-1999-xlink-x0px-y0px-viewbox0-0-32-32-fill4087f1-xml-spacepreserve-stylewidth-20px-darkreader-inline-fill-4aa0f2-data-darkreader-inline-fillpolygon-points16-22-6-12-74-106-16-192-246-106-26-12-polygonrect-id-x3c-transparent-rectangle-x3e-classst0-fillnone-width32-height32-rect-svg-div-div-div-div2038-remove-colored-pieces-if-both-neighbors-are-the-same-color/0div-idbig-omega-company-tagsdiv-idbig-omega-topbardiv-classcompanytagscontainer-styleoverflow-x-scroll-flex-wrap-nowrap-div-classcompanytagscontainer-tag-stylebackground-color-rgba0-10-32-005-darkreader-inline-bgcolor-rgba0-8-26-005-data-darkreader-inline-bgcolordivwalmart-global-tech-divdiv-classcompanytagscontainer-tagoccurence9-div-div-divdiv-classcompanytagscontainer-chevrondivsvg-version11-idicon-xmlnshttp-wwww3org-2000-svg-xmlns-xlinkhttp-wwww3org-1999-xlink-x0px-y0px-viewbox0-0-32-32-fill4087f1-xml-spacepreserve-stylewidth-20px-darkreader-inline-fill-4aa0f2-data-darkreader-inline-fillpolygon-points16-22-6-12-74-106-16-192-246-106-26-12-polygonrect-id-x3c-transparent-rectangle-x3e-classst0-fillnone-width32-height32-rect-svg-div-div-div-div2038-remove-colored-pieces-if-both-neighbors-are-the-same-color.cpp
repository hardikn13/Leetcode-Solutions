class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.size();
        
        int a = 0, temp = 1;
        for(int i = 1; i < n; i++)
        {
            if(colors[i] == 'A' && colors[i - 1] == 'A')
            {
                temp++;
                if(temp > 2)
                    a++;
            }
            else if(colors[i] == 'B')
                temp = 0;
            else
                temp = 1;
        }
        
        int b = 0, tempo = 1;
        for(int i = 1; i < n; i++)
        {
            if(colors[i] == 'B' && colors[i - 1] == 'B')
            {
                tempo++;
                if(tempo > 2)
                    b++;
            }
            else if(colors[i] == 'A')
                tempo = 0;
            else
                tempo = 1;
        }
        cout<<a<<b<<endl;
        
        if(a > b)
            return true;
        return false;
    }
};