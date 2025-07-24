# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        l = []
        dummy = ListNode()
        dummy.next = head
        node = head
        while node:
            l.append(node)
            node = node.next
        i = 0
        j = len(l) - 1
        pre = dummy
        while i < j:
            pre.next = l[i]
            l[i].next = l[j]
            pre = l[j]
            i = i + 1
            j = j - 1
        if i == j:
            pre.next = l[i]
            l[i].next = None
        if i > j:
            pre.next = None
        return dummy.next