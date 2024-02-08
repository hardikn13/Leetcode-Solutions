#include <vector>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> squares;
        for(int i = 1; i * i <= n; i++)
            squares.push_back(i * i);

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for(int square : squares)
            {
                if(i - square >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - square]);
            }
        }

        return dp[n];
    }
};





// MEMOIZATION
// -----------

// bool isPerfectSquare(int n) {
//         int root = sqrt(n);
//         return root * root == n;
//     }

//     int f(int ind, vector<int> &dp) {
//         if (ind <= 0)
//             return 0;
        
//         if(dp[ind] != -1)
//             return dp[ind];

//         int count = INT_MAX;

//         for(int i = ind; i > 0; i--)
//         {
//             if(isPerfectSquare(i))
//                 count = min(count, 1 + f(ind - i, dp));
//         }

//         return dp[ind] = count;
//     }

//     int numSquares(int n) {
        
//         vector<int> dp(n + 1, -1);
//         return f(n, dp);
        
//     }





// MATHEMATICAL
// ------------

// class Solution 
// {  
// private:  
//     int is_square(int n)
//     {  
//         int sqrt_n = (int)(sqrt(n));  
//         return (sqrt_n*sqrt_n == n);  
//     }
    
// public:
//     // Based on Lagrange's Four Square theorem, there 
//     // are only 4 possible results: 1, 2, 3, 4.
//     int numSquares(int n) 
//     {  
//         // If n is a perfect square, return 1.
//         if(is_square(n)) 
//         {
//             return 1;  
//         }
        
//         // The result is 4 if and only if n can be written in the 
//         // form of 4^k*(8*m + 7). Please refer to 
//         // Legendre's three-square theorem.
//         while ((n & 3) == 0) // n%4 == 0  
//         {
//             n >>= 2;  
//         }
//         if ((n & 7) == 7) // n%8 == 7
//         {
//             return 4;
//         }
        
//         // Check whether 2 is the result.
//         int sqrt_n = (int)(sqrt(n)); 
//         for(int i = 1; i <= sqrt_n; i++)
//         {  
//             if (is_square(n - i*i)) 
//             {
//                 return 2;  
//             }
//         }  
        
//         return 3;  
//     }  
// };