/*************************************************************************
    > File Name: courseScheduleII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-28 17:33:45
 ************************************************************************/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degrees(numCourses);
        for (const auto& pair : prerequisites)
        {
            const int from = pair.second;
            const int to = pair.first;
            graph[from].push_back(to);
            in_degrees[to]++;
        }
        
        queue<int> que;
        for (int i = 0; i < numCourses; i++)
        {
            if (in_degrees[i] == 0)
            {
                que.push(i);
            }
        }
        
        vector<int> res;
        while (!que.empty())
        {
            int front = que.front();
            que.pop();
            res.push_back(front);
            for (int to : graph[front])
            {
                if (--in_degrees[to]== 0)
                {
                    que.push(to);
                }
            }
        }
        
        if (res.size() != numCourses)
        {
            res.clear();
        }
        
        return res;
    }
};
