/*************************************************************************
    > File Name: removeLinkedListElements.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 19:30:51
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
        {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        ListNode* next;
        while (cur)
        {
            next = cur->next;
            if (next && next->val == val)
            {
                cur->next = next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        
        return dummy.next;
    }
};
