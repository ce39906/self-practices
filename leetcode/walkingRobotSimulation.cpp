/*************************************************************************
    > File Name: walkingRobotSimulation.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-31 16:49:10
 ************************************************************************/
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for (const auto& ob : obstacles)
        {
            obs.insert(to_string(ob[0]) + " " + to_string(ob[1]));
        }
        
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        
        int dir_idx = 0;
        int res = 0;
        pair<int, int> pos(0, 0);
        for (int command : commands)
        {
            if (command == -1)
            {
                dir_idx++;
                if (dir_idx == 4)
                {
                    dir_idx = 0;
                }
            }
            else if (command == -2)
            {
                dir_idx--;
                if (dir_idx == -1)
                {
                    dir_idx = 3;
                }
            }
            else
            {
                const pair<int, int>& direction = directions[dir_idx];
                string next_pos = to_string(pos.first + direction.first) + " " + to_string(pos.second + direction.second);
                while (command-- && !obs.count(next_pos))
                {
                    pos.first += direction.first;
                    pos.second += direction.second;
                    next_pos = to_string(pos.first + direction.first) + " " + to_string(pos.second + direction.second);
                }
            }
            
            res = max(res, pos.first * pos.first + pos.second * pos.second);
        }
        
        return res;
    }
};
