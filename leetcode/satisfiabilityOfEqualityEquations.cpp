/*************************************************************************
    > File Name: satisfiabilityOfEqualityEquations.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-12 19:25:23
 ************************************************************************/
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        uf.resize(26);
        iota(uf.begin(), uf.end(), 0);
        for (string& equation : equations)
        {
            if (equation[1] == '=')
            {
                uf[find(equation[0] - 'a')] = find(equation[3] - 'a');
            }
        }

        for (string& equation : equations)
        {
            if (   equation[1] == '!'
                && find(equation[0] - 'a') == find(equation[3] - 'a'))
            {
                return false;
            }
        }

        return true;
    }
private:
    int find(int x)
    {
        if (x != uf[x])
        {
            uf[x] = find(uf[x]);
        }

        return uf[x];
    }
    vector<int> uf;
};
