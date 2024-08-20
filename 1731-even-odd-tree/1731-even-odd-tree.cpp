class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool even = true;
        while(!q.empty())
        {
            int size = q.size();

            int prev = INT_MAX;
            if(even)
                prev = INT_MIN;

            while(size--)
            {
                auto current = q.front();
                q.pop();

                if((even && (current -> val % 2 == 0 || current -> val <= prev)) || 
                        (!even && (current -> val % 2 == 1 || current -> val >= prev)))
                    return false;

                prev = current -> val;
                
                if(current -> left)
                    q.push(current -> left);

                if(current -> right)
                    q.push(current -> right);
            }
            
            even = !even;
        }
        
        return true;
    }
};