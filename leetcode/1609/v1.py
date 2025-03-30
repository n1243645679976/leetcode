# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        bfs = deque([(root, 1,)])
        nlayer = 1
        lastlayer = 0
        lastval = 0
        while bfs:
            node, layer = bfs.popleft()
            if lastlayer != layer:
                lastval = node.val
                lastlayer = layer
                nlayer = layer
                if layer & 1: 
                    if not (node.val & 1):
                        return False
                else:
                    if (node.val & 1):
                        return False
            else:
                if layer & 1:
                    if node.val <= lastval:
                        return False
                    if (node.val & 1) == 0:
                        return False
                        
                else:
                    if node.val >= lastval:
                        return False
                    if (node.val & 1):
                        return False
                lastval = node.val
            if node.left:
                bfs.append((node.left, layer+1))
            if node.right:
                bfs.append((node.right, layer+1))
        return True