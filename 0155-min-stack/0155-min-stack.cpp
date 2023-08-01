class MinStack {
    
public:
    vector<pair<int, int>> s;
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push_back({val, val});
        }
        else
        {
            s.push_back({val, min(val, s.back().second)});
        }
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};




// USING STACK AND A VARIABLE
// --------------------------
// public:
//     stack<int> minStack;
//     long long mini = INT_MAX;
//     MinStack() {
//     }
    
//     void push(int val) {
//         if(minStack.empty())
//         {
//             minStack.push(val);
//             mini = val;
//         }
//         else
//         {
//             if(val < mini)
//             {
//                 long long data = 2 * (long long)val - mini;
//                 mini = val;
//                 minStack.push(data);
//             }
//             else
//             {
//                minStack.push(val);
//             }
//         }
//     }
    
//     void pop() {
//         int curr = minStack.top();
//         if(curr > mini)
//         {
//             minStack.pop();
//         }
//         else
//         {
//             int prevMin = mini;
//             long long data = 2 * (long long)mini - curr;
//             mini = data;
//             minStack.pop();
//         }
//     }
    
//     int top() {
//         if(minStack.empty())
//         {
//             return -1;
//         }
//         int curr = minStack.top();
        
//         if(curr < mini)
//         {
//             return mini;
//         }
//         else
//         {
//             return curr;
//         }
//     }
    
//     int getMin() {
//         return mini;
//     }

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */