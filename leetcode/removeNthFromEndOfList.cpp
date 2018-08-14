/*************************************************************************
    > File Name: removeNthFromEndOfList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-14 11:21:26
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // safety guard
        if (n <= 0 || !head)
        {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while (n--)
        {
            if (fast)
            {
                fast = fast->next;
            }
        }
        
        while (fast && fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* tmp = slow->next;
        if (tmp)
        {
            slow->next = tmp->next;
        }
        
        return dummy->next;
    }
};
