/*************************************************************************
    > File Name: sortList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-15 19:54:55
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        // break to 2 list
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* right_part = slow->next;
        slow->next = NULL;
        ListNode* left_sorted = sortList(head);
        ListNode* right_sorted = sortList(right_part);
        
        return mergeSort(left_sorted, right_sorted);
    }
private:
    ListNode* mergeSort(ListNode* head1, ListNode* head2) const
    {
        if (!head1)
        {
            return head2;
        }
        
        if (!head2)
        {
            return head1;
        }
        
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (head1 && head2)
        {
            if (head1->val < head2->val)
            {
                cur->next = head1;
                head1 = head1->next;
            }
            else
            {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        
        if (head1)
        {
            cur->next = head1;
        }
        
        if (head2)
        {
            cur->next = head2;
        }
      
        
        return dummy.next;
    }
};
