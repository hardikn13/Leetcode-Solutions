class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.size();
        int high = 0, low = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                low++;
                high++;
            }
            
            if(s[i] == ')')
            {
                low = max(0, low - 1);
                high--;
            }
            
            if(s[i] == '*')
            {
                low = max(0, low - 1);
                high++;
            }
            
            if(high < 0)
                return false;
        }
        
        return (low == 0);
    }
};




// ANOTHER APPROACH
// ----------------

//     bool checkValidString(string s) {
        
//         int len = s.length();
//         stack<int> open,star;
        
//         for(int i = 0;i<len ; i++)
//         {
//             if(s[i] == '(')
//                 open.push(i);
//             else if(s[i] == '*')
//                 star.push(i);
//             else
//             {
//                 if(!open.empty())
//                     open.pop();
//                 else if(!star.empty())
//                     star.pop();
//                 else
//                 {
//                     return false;
//                 }
//             }
//         }
        
//         // till my open is not emptied
        
//         while(!open.empty())
//         {
//             if(open.top()>star.top())
//                 return false;
//             else //if(open.top()<star.top())
//                 {
//                 open.pop();
//                 star.pop();
//                 }
//             if(star.empty())
//                 return false;
//         }
//         return true;
//     }