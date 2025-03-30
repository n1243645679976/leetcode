# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        q = ListNode()
        q.next = l1
        head = q
        q2 = ListNode()
        q2.next = l2
        c = 0
        while q.next and q2.next:
            q.next.val += q2.next.val + c
            if q.next.val >= 10:
                q.next.val -= 10
                c = 1
            else:
                c = 0
                
            q = q.next
            q2 = q2.next
            
        if q2.next:
            q.next = q2.next
            
        while q.next:
            q.next.val += c
            if q.next.val >= 10:
                q.next.val -= 10
                c = 1
            else:
                c = 0
            q = q.next
        
        if c:
            q.next = ListNode(1)
        return head.next