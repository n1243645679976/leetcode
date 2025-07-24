# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        headL = ListNode()
        headGE = ListNode()
        nodeL = headL
        nodeGE = headGE
        node = head
        while node:
            # print(node)
            if node.val >= x:
                nodeGE.next = node
                nodeGE = nodeGE.next
            else:
                nodeL.next = node
                nodeL = nodeL.next
            node = node.next
        nodeL.next = headGE.next
        nodeGE.next = None
        return headL.next