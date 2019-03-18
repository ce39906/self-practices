/*************************************************************************
    > File Name: designLinkedList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-18 18:50:07
 ************************************************************************/
struct Node
{
    Node(int val) : val(val), prev(nullptr), next(nullptr)
    {
    }

    int val;
    Node* prev;
    Node* next;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy_head = new Node(-1);
        dummy_tail = new Node(-1);
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* cur = dummy_head->next;
        while (cur && index--)
        {
            cur = cur->next;
        }

        if (!cur)
        {
            return -1;
        }
        return cur->val; 
    }
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->prev = dummy_head;
        node->next = dummy_head->next;
        dummy_head->next->prev = node;
        dummy_head->next = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        node->next = dummy_tail;
        node->prev = dummy_tail->prev;
        dummy_tail->prev->next = node;
        dummy_tail->prev = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node* cur = dummy_head;
        while(cur && index--)
        {
            cur = cur->next;
        }

        if (cur == dummy_tail)
        {
            return;
        }

        Node* node = new Node(val);
        Node* next = cur->next;
        node->next = next;
        next->prev = node;
        node->prev = cur;
        cur->next = node;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* cur = dummy_head;
        while (cur && index--)
        {
            cur = cur->next;
        }

        if (cur == dummy_tail || cur->next == dummy_tail)
        {
            return;
        }

        Node* next = cur->next;
        cur->next = next->next;
        cur->next->prev = cur;
        delete next;
    }
private:
    Node* dummy_head;
    Node* dummy_tail;
};
