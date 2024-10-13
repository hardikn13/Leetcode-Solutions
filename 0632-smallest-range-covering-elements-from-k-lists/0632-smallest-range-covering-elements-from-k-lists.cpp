class Node
{
    public:
    
    int val;
    int row;
    int col;
    
    Node(int d, int r, int c)
    {
        val = d;
        row = r;
        col = c;
    }
};

class compare
{
    public:
    
    bool operator()(Node* a, Node* b)
    {
        return a -> val > b -> val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, compare> pq;
        int k = nums.size();
        
        for(int i = 0; i < k; i++)
        {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            pq.push(new Node(element, i, 0));
        }
        
        int start = mini;
        int end = maxi;
        
        while(!pq.empty())
        {
            Node* temp = pq.top();
            pq.pop();
            mini = temp -> val;
            
            if(maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }
            
            if(temp -> col + 1 < nums[temp -> row].size())
            {
                maxi = max(maxi, nums[temp -> row][temp -> col + 1]);
                pq.push(new Node(nums[temp->row][temp->col + 1], temp -> row, temp -> col + 1));
            }
            else
            {
                break;
            }
        }
        return {start, end};
    }
};