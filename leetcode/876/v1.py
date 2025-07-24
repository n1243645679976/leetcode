# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        count = 0
        node = head
        while node:
            count += 1
            node = node.next
        node = head
        count = (count)//2
        while count:
            node = node.next
            count -= 1
        return node
            