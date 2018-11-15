/*************************************************************************
    > File Name: insertionSortList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-14 13:09:09
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode dummy(0);
        ListNode* prev = &dummy;
        ListNode* cur = head;
        ListNode* next = NULL;
        
        while (cur)
        {
            next = cur->next;
            while (prev->next && prev->next->val < cur->val)
            {
                prev = prev->next;
            }
            // insert between prev and prev->next
            cur->next = prev->next;
            prev->next = cur;
            cur = next;
            prev = &dummy;
        }
        
        return dummy.next;
    }
};
