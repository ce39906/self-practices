/*************************************************************************
    > File Name: flattenNestedListIterator.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 16:09:52
 ************************************************************************/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        
    }

    int next() {
        int val = intergers[cur++];
        return val;
    }

    bool hasNext() {
        return cur + 1 <= intergers.size();
    }
private:
    vector<int> intergers;
    size_t cur = 0;
    void dfs(const vector<NestedInteger>& nestedList)
    {
        for (const auto& nested : nestedList)
        {
            if (nested.isInteger())
            {
                intergers.push_back(nested.getInteger());
            }
            else
            {
                dfs(nested.getList());
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
