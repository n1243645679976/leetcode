"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        node_list = []
        node_dict = {None:-1}
        node = head
        i = 0
        while node:
            node_list.append(Node(node.val))
            node_dict[node] = i
            i += 1
            node = node.next
        node = head
        i = 0
        node_list.append(None)
        while node:
            node_list[i].next = node_list[i+1]
            node_list[i].random = node_list[node_dict[node.random]]
            i += 1
            node = node.next
        return node_list[0]
            
            