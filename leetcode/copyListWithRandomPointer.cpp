/*************************************************************************
    > File Name: copyListWithRandomPointer.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-09 19:14:43
 ************************************************************************/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
        {
            return NULL;
        }
        RandomListNode dummy(0);
        RandomListNode* cur = &dummy;
        unordered_map<RandomListNode*, size_t> node_2_idx;
        vector<RandomListNode*> new_list_nodes;
        RandomListNode* ori_head = head;
        size_t idx = 0;
        while (head)
        {
            node_2_idx[head] = idx;
            idx++;
            RandomListNode* node = new RandomListNode(head->label);
            cur->next = node;
            cur = cur->next;
            head = head->next;
            new_list_nodes.push_back(node);
        }
        
        cur = ori_head;
        idx = 0;
        while (cur)
        {
            if (cur->random)
            {
                size_t random_node_idx = node_2_idx[cur->random];
                new_list_nodes[idx]->random = new_list_nodes[random_node_idx];
            }
            idx++;
            cur = cur->next;
        }
        
        return new_list_nodes.front();
    }
};
