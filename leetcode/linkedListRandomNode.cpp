/*************************************************************************
    > File Name: linkedListRandomNode.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-27 19:13:27
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ori_head = head;
        while(head)
        {
            length++;
            head = head->next;
        }
    
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int step = rd() % length;
        int i = 0;
        ListNode* cur = ori_head;
        while(i < step)
        {
            cur = cur->next;
            i++;
        }
        return cur->val;
    }
    
    int length = 0;
    std::random_device rd;
    ListNode* ori_head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
