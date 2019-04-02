/*************************************************************************
    > File Name: reconstructItinerary.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-01 15:16:39
 ************************************************************************/
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        if (tickets.empty())
        {
            return {};
        }

        map<string, multiset<string>> graph;
        for (const auto& ticket : tickets)
        {
            const string& from = ticket.first;
            const string& to = ticket.second;
            if (graph.count(from))
            {
                graph[from].insert(to);
            }
            else
            {
                graph[from] = {to};
            }
            
        }
        vector<string> path;
        dfs(graph, "JFK", path);
        reverse(path.begin(), path.end());
        return path;
    }
private:
    void dfs(map<string, multiset<string>>& graph,
             const string& start,
             vector<string>& path)
    {
        while (!graph[start].empty())
        {
            const string next = *graph[start].begin();
            graph[start].erase(graph[start].begin());
            dfs(graph, next, path);
        }
        path.push_back(start);
    }
};
