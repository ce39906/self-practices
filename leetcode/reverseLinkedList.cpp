/*************************************************************************
    > File Name: reverseLinkedList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-27 11:56:39
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode* prev = head;
        ListNode* cur = head->next;
        
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = NULL;
        return prev;
    }
};
