class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        q = []
        for i, n in enumerate(lists):
            if n != None:
                heapq.heappush(q, (n.val, i))
        head = ListNode()
        node = head
        while q:
            num, ind = heapq.heappop(q)
            node.next = lists[ind]
            lists[ind] = lists[ind].next
            if lists[ind]:
                heapq.heappush(q, (lists[ind].val, ind))
            node = node.next
        return head.next