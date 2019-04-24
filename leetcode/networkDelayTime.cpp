/*************************************************************************
    > File Name: networkDelayTime.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-24 10:22:36
 ************************************************************************/
struct Node
{
    Node (int label, int weight) : label(label), weight(weight)
    {
    }

    int label;
    int weight;
};

struct Cmp
{
    bool operator() (Node& lhs, Node& rhs)
    {
        return lhs.weight > rhs.weight;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<Node>> graph;
        for (const auto time : times)
        {
            const int from = time[0];
            const int to = time[1];
            const int weight = time[2];
            if (graph.count(from))
            {
                graph[from].emplace_back(to, weight);
            }
            else
            {
                vector<Node> adjs;
                adjs.emplace_back(to, weight);
                graph[from] = adjs;
            }
        }

        priority_queue<Node, vector<Node>, Cmp> pq;
        unordered_map<int, int> visited;
        visited[K] = 0;
        // search
        pq.push(Node(K, 0));
        while (!pq.empty())
        {
            Node top = pq.top();
            pq.pop();
            int label = top.label;
            int weight = top.weight;
            if (visited.count(label) && visited[label] < weight)
            {
                continue;
            }

            if (!graph.count(label))
            {
                continue;
            }

            for (const Node& node : graph.at(label))
            {
                if (visited.count(node.label) && visited[node.label] <= weight + node.weight)
                {
                    continue;
                }
                visited[node.label] = weight + node.weight;
                pq.emplace(node.label, weight + node.weight);
            }
        }

        if (visited.size() != N)
        {
            return -1;
        }

        int res = 0;
        for (auto cit = visited.cbegin(); cit != visited.cend(); ++cit)
        {
            res = max(res, cit->second);
        }
        
        return res;
    }
};
