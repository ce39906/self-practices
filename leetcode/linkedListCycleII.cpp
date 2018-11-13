/*************************************************************************
    > File Name: linkedListCycleII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-12 17:47:16
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
        {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
            {
                while (entry != slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
