/*************************************************************************
    > File Name: constructQuadTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-07 19:47:11
 ************************************************************************/
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (m == 0)
            return NULL;
        const int n = grid[0].size();
        if (m != n)
        {
            return NULL;
        }
        
        int sum = 0;
        for (const auto& row : grid)
        {
            for (const auto num : row)
            {
                sum += num;
            }
        }
        
        if (sum == m * m || sum == 0)
        {
            return new Node(grid[0][0], 1, NULL, NULL, NULL, NULL);
        }
        
        vector<vector<int>> top_left;
        vector<vector<int>> top_right;
        vector<vector<int>> bottom_left;
        vector<vector<int>> bottom_right;
        
        const int half = m >> 1;
        for (int i = 0; i < half; i++)
        {
            top_left.push_back(vector<int>(grid[i].begin(), grid[i].begin() + half));
            top_right.push_back(vector<int>(grid[i].begin() + half, grid[i].end()));
            bottom_left.push_back(vector<int>(grid[i + half].begin(), grid[i + half].begin() + half));
            bottom_right.push_back(vector<int>(grid[i + half].begin() + half, grid[i + half].end()));
        }
        
        return new Node(1,
                        0,
                        construct(top_left),
                        construct(top_right),
                        construct(bottom_left),
                        construct(bottom_right));
    }
};
