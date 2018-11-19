/*************************************************************************
    > File Name: intersectionOfTwoLinkedLists.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-19 15:34:35
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
        {
            return NULL;
        }
        
        const auto list_node_length = [](ListNode* head){
            int length = 0;
            while (head)
            {
                length++;
                head = head->next;
            }
            return length;
        };
        
        int length_a = list_node_length(headA);
        int length_b = list_node_length(headB);
        
        while (length_a > length_b)
        {
            headA = headA->next;
            length_a--;
        }
        
        while (length_a < length_b)
        {
            headB = headB->next;
            length_b--;
        }
        
        while (headA)
        {
            if (headA == headB)
            {
                return headA;
            }
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
