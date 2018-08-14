/*************************************************************************
    > File Name: reverseNodesInKGroup.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-14 19:58:21
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next)
        {
            return head;
        }
        
        int i = 1;
        ListNode* group_tail = head;
        while(group_tail && i < k)
        {
            group_tail = group_tail->next;
            i++;
        }
        // not enough
        if (!group_tail)
        {
            return head;
        }
        
        ListNode* next_group_head = group_tail->next;
        // reverse fisrt k nodes
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(prev != group_tail)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        head->next = reverseKGroup(next_group_head, k);
        return group_tail;
    }
};
