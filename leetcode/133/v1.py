"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if node == None:
            return None
        visited = set()
        int2node = {1:Node(1)}
        def dfs(node):
            visited.add(node.val)
            for n in node.neighbors:
                if n.val not in int2node:
                    int2node[n.val] = Node(n.val)
                int2node[n.val].neighbors.append(int2node[node.val])
                if n.val not in visited:
                    dfs(n)
            return node
        dfs(node)
        
        return int2node[1]
            