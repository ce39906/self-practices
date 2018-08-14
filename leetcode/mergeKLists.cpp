/*************************************************************************
    > File Name: mergeKLists.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-14 16:16:27
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
        {
            return NULL;
        }
        
        list<ListNode*> linked_lists(lists.begin(), lists.end());
        while (linked_lists.size() > 1)
        {
            ListNode* l1 = linked_lists.back();
            linked_lists.pop_back();
            ListNode* l2 = linked_lists.back();
            linked_lists.pop_back();
            linked_lists.push_front(merge2Lists(l1, l2));
        }
        
        return linked_lists.front();
    }
private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) const
    {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
