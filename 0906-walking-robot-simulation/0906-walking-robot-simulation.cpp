class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(auto &it : obstacles)
            st.insert(to_string(it[0]) + "," + to_string(it[1]));

        int x = 0, y = 0, direction = 0;
        vector<int> dirX = {0, 1, 0, -1};
        vector<int> dirY = {1, 0, -1, 0};
        
        int ans = 0;
        for(auto &it : commands)
        {
            if(it == -1)
                direction = (direction + 1) % 4;
            else if(it == -2)
                direction = (direction + 3) % 4;
            else
            {
                for(int i = 0; i < it; i++)
                {
                    int nextX = x + dirX[direction];
                    int nextY = y + dirY[direction];

                    if(st.find(to_string(nextX) + "," + to_string(nextY)) == st.end())
                    {
                        x = nextX;
                        y = nextY;
                        ans = max(ans, x * x + y * y);
                    }
                    else
                        break;
                }
            }
        }

        return ans;
    }
};
