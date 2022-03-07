# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        dummy = ListNode()
        node = dummy
        while list1 and list2:
            if list1.val > list2.val:
                node.next = list2
                list2, node = list2.next, list2
            else:
                node.next = list1
                list1, node = list1.next, list1
        
        if list1:
            node.next = list1
        if list2:
            node.next = list2
        return dummy.next