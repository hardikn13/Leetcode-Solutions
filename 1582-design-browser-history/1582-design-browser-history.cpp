class BrowserHistory {
public:
    class Node {
        public:
            string url;
            Node* prev = NULL;
            Node* next = NULL;
            
            Node(string url)
            {
                this -> url = url;
            }
    };

    Node* curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* add = new Node(url);
        curr -> next = add;
        add -> prev = curr;
        curr = add;
    }
    
    string back(int steps) {
        while(steps)
        {
            if(curr -> prev != NULL)
                curr = curr -> prev;
            else
                break;

            steps--;
        }

        return curr -> url;
    }
    
    string forward(int steps) {
        while(steps)
        {
            if(curr -> next != NULL)
                curr = curr -> next;
            else
                break;

            steps--;
        }

        return curr -> url;
    }
};





// ANOTHER APPROACH
// ----------------

// class BrowserHistory {
// public:
//     stack<string> bwd;
//     stack<string> fwd;
//     BrowserHistory(string homepage) {
//         bwd.push(homepage);
//     }
    
//     void visit(string url) {
//         while(!fwd.empty())
//             fwd.pop();
//         bwd.push(url);
//     }
    
//     string back(int steps) {
        
//         while(bwd.size() > 1 && steps > 0)
//         {
//             fwd.push(bwd.top());
//             bwd.pop();
//             steps--;
//         }

//         return bwd.top();
//     }
    
//     string forward(int steps) {

//         while(!fwd.empty() && steps > 0)
//         {
//             bwd.push(fwd.top());
//             fwd.pop();
//             steps--;
//         }

//         return bwd.top();
//     }
// };