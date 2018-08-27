/*************************************************************************
    > File Name: rotateList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-27 19:13:39
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
        {
            return head;
        }
        
        int length = 1;
        ListNode* cur = head;
        while (cur->next)
        {
            length++;
            cur = cur->next;
        }
        
        ListNode* last = cur;
        
        k = k % length;
        cur = head;
        for (int i = 0;  i < length - k - 1; i++)
        {
            cur = cur->next;
        }
        
        ListNode* new_head = cur->next;
        if (!new_head)
        {
            return head;
        }
        cur->next = NULL;
        last->next = head;
        return new_head;
    }
};
