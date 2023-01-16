class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        for(int i=1;i<=n;i++)
        {
            if(i%3==0&&i%5==0)
            {
                s.emplace_back("FizzBuzz");
            }
            else if(i%3==0&&i%5!=0)
            {
                s.emplace_back("Fizz");
            }
            else if(i%5==0&&i%3!=0)
            {
                s.emplace_back("Buzz");
            }
            else
            {
                s.emplace_back(std::to_string(i));
            }
        }
        return s;
    }
};


// Another Approach
// ----------------

// class Solution {
// public:
//     vector<string> fizzBuzz(int n) {
//         vector<string> res(n);
//         for(int i = 1;i <= n; i++) {
//             res[i - 1] = to_string(i);
//         }
//         for(int i = 2;i < n; i += 3) {
//             res[i] = "Fizz";
//         }
//         for(int i = 4;i < n; i += 5) {
//             res[i] = "Buzz";
//         }
//         for(int i = 14;i < n; i += 15) {
//             res[i] = "FizzBuzz";
//         }
//         return res;
//     }
// };