/*************************************************************************
    > File Name: minimumGeneticMutation.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-02 15:39:54
 ************************************************************************/
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.empty())
        {
            return -1;
        }
        buildGraph(bank);
        // search from end to start
        unordered_set<string> visited;
        queue<string> que;
        que.push(end);
        int res = 0;
        while (!que.empty())
        {
            res++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                string front = que.front();
                que.pop();
                if (visited.count(front))
                {
                    continue;
                }
                visited.insert(front);
                if (geneDiffCnt(front, start) == 1)
                {
                    return res;
                }

                if (!graph.count(front))
                {
                    continue;
                }
                const set<string>& adjs = graph.at(front);
                for (auto it = adjs.begin(); it != adjs.end(); ++it)
                {
                    if (visited.count(*it))
                    {
                        continue;
                    }

                    que.push(*it);
                }
            }
        }

        return -1;
    }
private:

    unordered_map<string, set<string>> graph;
    
    int geneDiffCnt(const string& gene1, const string& gene2)
    {
        int diff_num = 0;
        for (int i = 0; i < gene1.size(); i++)
        {
            if (gene1[i] != gene2[i])
            {
                diff_num++;
            }
        }

        return diff_num;
    }

    void buildGraph(const vector<string>& bank)
    {
        for (const string gene : bank)
        {
            for (const string adj : bank)
            {
                if (gene == adj)
                {
                    continue;
                }

                if (geneDiffCnt(gene, adj) == 1)
                {
                    graph[gene].insert(adj);
                }
            }
        }
    }
};
