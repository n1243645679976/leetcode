# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        root = ListNode()
        root.next = head
        prehead = root
        while head:
            if head.val == val:
                prehead.next = head.next
            else:
                prehead = prehead.next
            head = head.next
        return root.next
            