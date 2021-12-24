# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def dfs(node1, node2):
            if node1.val != node2.val:
                return False
            flag = True
            if (not node1.left and node2.right) or (node1.left and not node2.right):
                return False
            if (not node1.right and node2.left) or (node1.right and not node2.left):
                return False
            
            if node1.left and node2.right:
                flag = flag and dfs(node1.left, node2.right)
            if node1.right and node2.left:
                flag = flag and dfs(node1.right, node2.left)
            return flag
        return dfs(root, root)
            