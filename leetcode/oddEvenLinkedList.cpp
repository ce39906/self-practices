/*************************************************************************
    > File Name: oddEvenLinkedList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-20 19:14:51
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode odd_dummy(0);
        ListNode even_dummy(0);
        
        odd_dummy.next = head;
        even_dummy.next = head->next;
        
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        
        while (p2 && p2->next)
        {
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p1->next = even_dummy.next;
        return odd_dummy.next;
    }
};
