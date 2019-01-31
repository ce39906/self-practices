/*************************************************************************
    > File Name: middleOfTheLinkedList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-30 11:59:49
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
    ListNode* middleNode(ListNode* head) {
        if (!head) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
