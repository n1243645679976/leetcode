# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None:
            return head
        q = []
        node = head
        i = 0
        while node:
            q.append(node)
            node = node.next
            i += 1
        k %= i
        if k != 0:
            q[-1].next = q[0]
            q[-k-1].next = None
        return q[-k]
        
            