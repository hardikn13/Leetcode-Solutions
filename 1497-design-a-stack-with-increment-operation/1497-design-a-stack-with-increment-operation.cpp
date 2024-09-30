class CustomStack {
public:
    vector<int> v;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(v.size() == n)
            return;
        v.push_back(x);
    }
    
    int pop() {
        if(v.empty())
            return -1;
        int val = v.back();
        v.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        int t = 0;
        while(k && t < v.size())
        {
            v[t] += val;
            t++;
            k--;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */