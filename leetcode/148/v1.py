# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        q = []
        node = head
        while node:
            q.append(node.val)
            node = node.next
        q.sort()
        node = head
        i = 0
        while node:
            node.val = q[i]
            i = i+1
            node = node.next
        return head