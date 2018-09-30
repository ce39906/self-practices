/*************************************************************************
    > File Name: reverseLinkedListII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-30 15:38:00
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) 
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* front_prev = &dummy;
        ListNode* end = &dummy;
        
        for (int i = 1; i < m; i++)
        {
            front_prev = front_prev->next;
        }
        
        for (int i = 0; i < n; i++)
        {
            end = end->next;
        }
        
        ListNode* front = front_prev->next;
        ListNode* end_next = end->next;
        end->next = NULL;
        
        reverse(front);
        front_prev->next = end;
        front->next = end_next;
        
        return dummy.next;
    }
private:
    void reverse(ListNode* head)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        ListNode* prev = &dummy;
        ListNode* next = NULL;
        
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
};
