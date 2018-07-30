# coding: utf-8
__author__ = 'ce39906'
'''
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
'''
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
def removeNthFromEnd(self, head, n):
    start=ListNode(0)
    start.next=head
    slow=start
    fast=start
    i=1
    while i<=n+1:
        fast=fast.next
        i+=1
    while fast!=None:
        fast=fast.next
        slow=slow.next
    slow.next=slow.next.next
    return start.next