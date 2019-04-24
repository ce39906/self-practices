/*************************************************************************
    > File Name: reorganizeString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-24 16:01:54
 ************************************************************************/
struct Node
{
    Node (char c, int count) : c(c), count(count)
    {
    }

    char c;
    int count;
};

struct Cmp
{
    bool operator() (const Node& lhs, const Node& rhs)
    {
        return lhs.count < rhs.count;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> table(26, 0);
        for (const char c : S)
        {
            table[c - 'a']++;
            if (table[c - 'a'] > (S.size() + 1) / 2)
            {
                return "";
            }
        }
        priority_queue<Node, vector<Node>, Cmp> pq;
        for (int i = 0; i < table.size(); i++)
        {
            if (table[i] > 0)
            {
                pq.emplace('a' + i, table[i]);
            }
        }

        string res;
        res.reserve(S.size());
        while (!pq.empty())
        {
            Node top = pq.top();
            pq.pop();
            if (res.size() == 0 || res.back() != top.c)
            {
                res.append(1, top.c);
                if (--top.count > 0)
                {
                    pq.emplace(top.c, top.count);
                }
            }
            else
            {
                Node second = pq.top();
                pq.pop();
                res.append(1, second.c);
                if (--second.count > 0)
                {
                    pq.emplace(second.c, second.count);
                }
                pq.push(top);
            }
        }
    
        return res;
    }

};
