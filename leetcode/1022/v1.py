# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumRootToLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        def dfs(node, val):
            new_val = val * 2 + node.val
            if not node.left and not node.right:
                self.ans += new_val
            if node.left:
                dfs(node.left, new_val)
            if node.right:
                dfs(node.right, new_val)
        
        dfs(root, 0)
        return self.ans