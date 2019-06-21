/*************************************************************************
    > File Name: flowerPlantingWithNoAdjacent.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-21 17:06:17
 ************************************************************************/
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N);
        vector<vector<int>> g(N);
        // init graph
        for (const auto& path : paths)
        {
            g[path[0] - 1].push_back(path[1] - 1);
            g[path[1] - 1].push_back(path[0] - 1);
        }

        for (int i = 0; i < N; i++)
        {
            bool used[5] = {};
            for (int j : g[i])
            {
                used[res[j]] = true;
            }
            for (int flower = 1; flower <= 4; flower++)
            {
                if (!used[flower]) res[i] = flower;
            }
        }

        return res;
    }
};
