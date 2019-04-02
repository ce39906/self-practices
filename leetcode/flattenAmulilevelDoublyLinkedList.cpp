/*************************************************************************
    > File Name: flattenAmulilevelDoublyLinkedList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-02 14:36:18
 ************************************************************************/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
        {
            return head;
        }

        if (!head->next && !head->child)
        {
            return head;
        }

        Node* cur = head;
        while (cur)
        {
            if (cur->child)
            {
                Node* next = cur->next;
                Node* child_head = flatten(cur->child);
                cur->child = nullptr;
                cur->next = child_head;
                child_head->prev = cur;
                Node* child_tail = findTail(child_head);
                child_tail->next = next;
                if (next) next->prev = child_tail;
                cur = next;
            }
            else
            {
                cur = cur->next;
            }
        }

        return head;
    }
private:
    Node* findTail(Node* head)
    {
        while (head->next)
        {
            head = head->next;
        }

        return head;
    }
};
