/*************************************************************************
    > File Name: removeDuplicatesFromSortedList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-12 18:13:25
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
        const int dummy_val = head->val - 1;
        ListNode dummy(dummy_val);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        ListNode* cur = head;
        
        while (cur)
        {
            if (prev->val == cur->val)
            {
                ListNode* tmp = cur->next;
                prev->next = tmp;
                cur = tmp;
            }
            else
            {
                prev = prev->next;
                cur = cur->next;
            }
        }
        
        return dummy.next;
    }
};
