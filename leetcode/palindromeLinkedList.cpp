/*************************************************************************
    > File Name: palindromeLinkedList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-06 11:27:25
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        while (head)
        {
            vec.push_back(head->val);
            head = head->next;
        }
        
        return isPalindrome(vec);
    }
private:
    bool isPalindrome(const vector<int>& vec) const
    {
        int i = 0;
        int j = vec.size() - 1;
        while (i < j)
        {
            if (vec[i++] != vec[j--])
            {
                return false;
            }
        }
        return true;
    }
};
