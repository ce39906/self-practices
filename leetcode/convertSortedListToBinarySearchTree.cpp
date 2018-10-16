/*************************************************************************
    > File Name: convertSortedListToBinarySearchTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-16 17:24:12
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
        {
            return NULL;
        }
        
        if (!head->next)
        {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        // find middle
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (fast && fast->next)
        {
            prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* right_head = slow->next;
        prev->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        TreeNode* left = sortedListToBST(head);
        TreeNode* right = sortedListToBST(right_head);
        
        root->left = left;
        root->right = right;
        return root;
        
    }
};
