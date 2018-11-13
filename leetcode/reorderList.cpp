/*************************************************************************
    > File Name: ReorderList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-13 11:15:15
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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
        {
            return;
        }
        // find middle
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head1 = slow->next;
        slow->next = NULL;
        // reverse right part
        ListNode* cur = head1->next;
        ListNode* prev = head1;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head1->next = NULL;
        // merge two list
        ListNode* cur1 = head;
        ListNode* cur2 = prev;
        while (cur1 && cur2)
        {
            ListNode* tmp1 = cur1->next;
            ListNode* tmp2 = cur2->next;
            cur1->next = cur2;
            cur2->next = tmp1;
            cur1 = tmp1;
            cur2 = tmp2;
        }
    }
};
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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
        {
            return;
        }
        vector<ListNode*> list_nodes;
        ListNode* cur = head;
        while (cur)
        {
            list_nodes.push_back(cur);
            cur = cur->next;
        }

        int i = 0;
        int j = list_nodes.size() - 1;
        while (i + 1 < j)
        {
            list_nodes[i]->next = list_nodes[j];
            list_nodes[j]->next = list_nodes[i + 1];
            list_nodes[j - 1]->next = NULL;
            i++;
            j--;
        }
    }
};
