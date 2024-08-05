class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        size -= 1;
        while(size--)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int z = q.front();
        q.pop();
        return z;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};




// ANOTHER APPROACH
// ----------------

// class MyStack {
// public:
//     queue<int> q1, q2;

//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q2.push(x);

//         while(!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         swap(q1, q2);
//     }
    
//     int pop() {
//         int z = q1.front();
//         q1.pop();
//         return z;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };