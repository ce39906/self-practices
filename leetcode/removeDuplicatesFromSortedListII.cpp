/*************************************************************************
    > File Name: removeDuplicatesFromSortedListII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-10 17:48:10
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        // make sure dummy has different val with head
        const int dummy_val = head->val - 1;
        ListNode dummy(dummy_val);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;
        int last_val = dummy_val;
        
        while (cur)
        {
            while (cur->next && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            // do not find dulicates
            if (cur == prev->next)
            {
                prev = prev->next;
                cur = cur->next;
            }
            else
            {
                prev->next = cur->next;
                cur = cur->next;
            }
        }
        
        return (&dummy)->next;
    }
};
