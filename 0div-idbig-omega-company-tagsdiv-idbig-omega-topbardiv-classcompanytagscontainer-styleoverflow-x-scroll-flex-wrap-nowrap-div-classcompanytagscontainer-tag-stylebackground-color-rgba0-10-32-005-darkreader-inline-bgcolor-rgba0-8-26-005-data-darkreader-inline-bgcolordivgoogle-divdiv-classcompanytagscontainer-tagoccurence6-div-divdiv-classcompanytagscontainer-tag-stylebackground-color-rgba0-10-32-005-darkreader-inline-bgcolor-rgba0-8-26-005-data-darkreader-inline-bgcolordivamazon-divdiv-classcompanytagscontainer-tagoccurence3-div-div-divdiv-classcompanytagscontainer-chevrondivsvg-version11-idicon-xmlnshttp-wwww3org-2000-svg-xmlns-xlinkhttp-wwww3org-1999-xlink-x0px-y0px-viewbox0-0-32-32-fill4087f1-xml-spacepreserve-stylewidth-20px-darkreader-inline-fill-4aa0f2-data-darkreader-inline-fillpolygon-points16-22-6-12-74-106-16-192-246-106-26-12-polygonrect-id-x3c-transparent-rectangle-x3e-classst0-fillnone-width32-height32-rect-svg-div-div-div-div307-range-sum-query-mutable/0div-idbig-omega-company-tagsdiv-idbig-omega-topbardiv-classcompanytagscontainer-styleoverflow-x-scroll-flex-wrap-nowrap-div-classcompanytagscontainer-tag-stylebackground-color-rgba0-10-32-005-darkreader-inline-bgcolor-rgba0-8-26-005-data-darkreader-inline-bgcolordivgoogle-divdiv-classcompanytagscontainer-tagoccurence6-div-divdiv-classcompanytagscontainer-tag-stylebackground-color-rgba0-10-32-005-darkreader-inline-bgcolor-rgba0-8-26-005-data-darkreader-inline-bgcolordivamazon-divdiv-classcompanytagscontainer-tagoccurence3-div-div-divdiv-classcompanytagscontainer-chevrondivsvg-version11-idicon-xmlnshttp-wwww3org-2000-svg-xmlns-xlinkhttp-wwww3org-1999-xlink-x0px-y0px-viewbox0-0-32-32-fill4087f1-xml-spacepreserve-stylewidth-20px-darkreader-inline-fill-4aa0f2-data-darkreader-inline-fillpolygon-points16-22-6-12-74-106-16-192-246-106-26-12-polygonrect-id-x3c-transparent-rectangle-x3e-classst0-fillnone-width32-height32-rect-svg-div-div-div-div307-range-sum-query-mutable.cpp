class NumArray {
public:
    vector<int> segmentTree;
    int n;
    void buildTree(int ind, int l, int r, vector<int> &nums)
    {
        if(l == r)
        {
            segmentTree[ind] = nums[l];
            return;
        }
        
        int mid = (l + r) / 2;
        
        buildTree(2 * ind + 1, l, mid, nums);
        buildTree(2 * ind + 2, mid + 1, r, nums);
        
        segmentTree[ind] = segmentTree[2 * ind + 1] + segmentTree[2 * ind + 2];
    }
    
    void segmentTreeUpdate(int ind, int val, int i, int l, int r)
    {
        if(l == r)
        {
            segmentTree[i] = val;
            return;
        }
        
        int mid = (l + r) / 2;
        
        if(ind <= mid)
            segmentTreeUpdate(ind, val, 2 * i + 1, l, mid);
        else
            segmentTreeUpdate(ind, val, 2 * i + 2, mid + 1, r);
        
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }
    
    int segmentTreeQuery(int start, int end, int ind, int l, int r)
    {
        if(r < start || l > end)
            return 0;
        
        if(l >= start && r <= end)
            return segmentTree[ind];
        
        int mid = (l + r) / 2;
        
        return segmentTreeQuery(start, end, 2 * ind + 1, l, mid) + 
            segmentTreeQuery(start, end, 2 * ind + 2, mid + 1, r);
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4 * n);
        buildTree(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        segmentTreeUpdate(index, val, 0, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return segmentTreeQuery(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */