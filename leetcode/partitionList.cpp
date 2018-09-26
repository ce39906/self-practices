/*************************************************************************
    > File Name: partitionList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-26 19:19:33
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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
        {
            return head;
        }
        
        ListNode large_dummy(0);
        ListNode small_dummy(0);
        ListNode* large_cur = &large_dummy;
        ListNode* small_cur = &small_dummy;
        ListNode* cur = head;
        
        while (cur)
        {
            if (cur->val < x)
            {
                small_cur->next = cur;
                small_cur = small_cur->next;
            }
            else
            {
                large_cur->next = cur;
                large_cur = large_cur->next;
            }
            cur = cur->next;
        }
        
        small_cur->next = large_dummy.next;
        large_cur->next = NULL;
        return small_dummy.next;
    }
};
