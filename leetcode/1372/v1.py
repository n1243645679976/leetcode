# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def longestZigZag(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        def dfs(node, prestep, count): #prestep 1: left prestep 2: right
            if node.left:
                if prestep == 1:
                    dfs(node.left, 1, 1)
                else:
                    dfs(node.left, 1, count+1)
            if node.right:
                if prestep == 2:
                    dfs(node.right, 2, 1)
                else:
                    dfs(node.right, 2, count+1)
            if count > self.ans:
                self.ans = count
            return
        dfs(root, 0, 0)
        return self.ans