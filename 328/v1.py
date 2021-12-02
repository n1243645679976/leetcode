# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        if not head.next:
            return head
        if head.next and not head.next.next:
            return head
        
        last2odd = head
        last2even = head.next
        first2 = head.next
        node = head.next.next
        noweven = False
        while node:
            if not noweven:
                last2odd.next = node
                last2odd = node
            else:
                last2even.next = node
                last2even = node
            noweven = not noweven
            node = node.next
        last2odd.next = first2
        last2even.next = None
        return head