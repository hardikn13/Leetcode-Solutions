class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        
        int sum = 0, n;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            sum = 0, n = size(q);
            for(int i = 0; i < n; i++)
            {
                auto top = q.front();
                q.pop();
                
                sum += top -> val;     
                
                if(top -> left)
                    q.push(top -> left);
                if(top -> right)
                    q.push(top -> right);
            }                
        }
        return sum;
    }
};