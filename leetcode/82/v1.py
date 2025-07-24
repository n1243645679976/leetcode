# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(-1e3)
        dummy.next = head
        if head == None:
            return None
        if head.next == None:
            return head
            
        def get_next(node, q):
            if node.next == None:
                return node.next, q
            if node.next.val != node.val:
                return node.next, q
            return get_next(node.next, q+1)
        
        node = dummy
        ans = []
        while node:
            _node, _q = get_next(node, 0)
            ans.append((node, _q))
            node = _node
        
        ans_ = ans[0][0]
        ans__ = ans_
        for n, q in ans[1:]:
            if q == 0:
                ans_.next = n
                ans_ = ans_.next
        ans_.next = None
        return ans__.next