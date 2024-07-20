class FreqStack {
public:
    unordered_map<int, int> mp;
    map<int, stack<int>> st;
    int maxi = INT_MIN;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        int a = mp[val];

        if(a >= maxi)
        {
            maxi = a;
        }
        st[a].push(val);
    }
    
    int pop() {
        int ans = st[maxi].top();
        st[maxi].pop();
        mp[ans]--;

        if(st[maxi].empty())
        {
            st.erase(maxi);
            maxi--;
        }

        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */