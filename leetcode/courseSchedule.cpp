/*************************************************************************
    > File Name: courseSchedule.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-27 19:14:08
 ************************************************************************/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degrees(numCourses, 0);
        for (const auto& pair : prerequisites)
        {
            int to = pair.first;
            int from = pair.second;
            in_degrees[to]++;
            graph[from].push_back(to);
        }
        
        int count = 0;
        queue<int> que;
        for (int i = 0; i < numCourses; i++)
        {
            if (in_degrees[i] == 0)
            {
                que.push(i);
                count++;
            }
        }
        
        while (!que.empty())
        {
            int front = que.front();
            que.pop();
            for (const int to : graph[front])
            {
                if (--in_degrees[to] == 0)
                {
                    que.push(to);
                    count++;
                }
            }
        }
        
        return count == numCourses;
    }
};
