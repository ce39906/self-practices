/*************************************************************************
    > File Name: swapNodesInPairs.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-14 19:29:00
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        // Swap first 2 Nodes
        ListNode* second = head->next;
        ListNode* third = second->next;
    
        second->next = head;
        head->next = swapPairs(third);
        
        return second;
    }
};
