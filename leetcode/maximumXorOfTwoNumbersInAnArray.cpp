/*************************************************************************
    > File Name: maximumXorOfTwoNumbersInAnArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-02 14:19:40
 ************************************************************************/
struct TrieNode
{
    TrieNode(int val) : val(val), left(nullptr), right(nullptr)
    {
    }

    int val;
    TrieNode* left;
    TrieNode* right;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        buildTree(nums);
        int res = 0;
        for (const int num : nums)
        {
            TrieNode* cur = root;
            int candidate = 0;
            for (int i = 31; i >= 0; i--)
            {
                int val = num & (1 << i);
                if (cur->left && cur->right)
                {
                    if (val == 0)
                    {
                        cur = cur->left;
                    }
                    else
                    {
                        cur = cur->right;
                    }
                }
                else
                {
                    cur = cur->left ? cur->left : cur->right;
                }
                candidate += val ^ (cur->val << i);
            }

            res = max(res, candidate);
        }

        return res;
    }
private:
    TrieNode* root;
    void buildTree(const vector<int>& nums)
    {
        root = new TrieNode(0);
        for (const int num : nums)
        {
            TrieNode* cur = root;
            for (int i = 31; i >= 0; i--)
            {
                int val = (num & (1 << i)) >> i;
                if (val == 1)
                {
                    if (!cur->left)
                    {
                        cur->left = new TrieNode(val);
                    }
                    cur = cur->left;
                }
                else
                {
                    if (!cur->right)
                    {
                        cur->right = new TrieNode(val);
                    }
                    cur = cur->right;
                }
            }
        }
    }
};
