/*************************************************************************
    > File Name: deleteNodeInALinkedList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-06 12:19:38
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
