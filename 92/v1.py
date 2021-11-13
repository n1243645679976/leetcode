# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        dummy = ListNode()
        dummy.next = head
        def dfs(node, k):
            if k == 0:
                return node, node.next
            # print(k, node.val)
            next_node = dfs(node.next, k-1)
            node.next.next = node
            return next_node
        
        
        prehead = dummy
        _left = left
        while _left > 1:
            _left -= 1
            prehead = prehead.next
        head = prehead.next
        
        left_node, last_node = dfs(prehead, right - left + 1)
        prehead.next.next = last_node
        prehead.next = left_node
        return dummy.next