/*************************************************************************
    > File Name: possibleBipartition.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-28 16:49:08
 ************************************************************************/
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> graph;
        for (const auto& dislike : dislikes)
        {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        
        // 0 : not visited
        // 1 : group 1
        // -1 : group -1
        vector<int> group(N + 1, 0);
        for (int i = 1; i <= N; i++)
        {
            if (group[i] == 0 && !dfs(graph, group, i, 1))
            {
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool dfs(const unordered_map<int, vector<int>>& graph,
             vector<int>& group,
             int i,
             int color) const
    {
        group[i] = color;
        if (!graph.count(i))
        {
            return true;
        }
        
        const vector<int>& adjs = graph.at(i);
        for (const int adj : adjs)
        {
            if (group[adj] == color)
            {
                return false;
            }
            
            if (group[adj] == 0 && !dfs(graph, group, adj, -color))
            {
                return false;
            }
        }
        
        return true;
    }
};
