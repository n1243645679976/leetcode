class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode()
        dummy_head.next = head
        node = dummy_head
        while True:
            if node.next == None:
                return dummy_head.next
            if node.next.next == None:
                return dummy_head.next
            next1 = node.next
            next2 = node.next.next
            temp = next2.next
            node.next = next2
            next2.next = next1
            next1.next = temp
            node = next1
        