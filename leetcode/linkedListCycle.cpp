/*************************************************************************
    > File Name: linkedListCycle.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-12 17:26:38
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
    bool hasCycle(ListNode *head) {
        if (!head)
        {
            return false;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        
        return false;
    }
};
