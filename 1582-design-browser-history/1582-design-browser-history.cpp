class BrowserHistory {
public:
    stack<string> bwd;
    stack<string> fwd;
    BrowserHistory(string homepage) {
        bwd.push(homepage);
    }
    
    void visit(string url) {
        while(!fwd.empty())
            fwd.pop();
        bwd.push(url);
    }
    
    string back(int steps) {
        
        while(bwd.size() > 1 && steps > 0)
        {
            fwd.push(bwd.top());
            bwd.pop();
            steps--;
        }

        return bwd.top();
    }
    
    string forward(int steps) {

        while(!fwd.empty() && steps > 0)
        {
            bwd.push(fwd.top());
            fwd.pop();
            steps--;
        }

        return bwd.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */