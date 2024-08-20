/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isAllSame(int x, int y, int n, vector<vector<int>> &grid)
    {
        int ele = grid[x][y];
        for(int i = x; i < x + n; i++)
            for(int j = y; j < y + n; j++)
                if(grid[i][j] != ele)
                    return false;
        return true;
    }   

    Node* f(int x, int y, int n, vector<vector<int>> &grid)
    {
        if(isAllSame(x, y, n, grid))
            return new Node(grid[x][y], true);
        else
        {
            Node* root = new Node(1, false);

            root -> topLeft = f(x, y, n / 2, grid);
            root -> topRight = f(x, y + n / 2, n / 2, grid);
            root -> bottomLeft = f(x + n / 2, y, n / 2, grid);
            root -> bottomRight = f(x + n / 2, y + n / 2, n / 2, grid);

            return root;
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        return f(0, 0, grid.size(), grid);
    }
};