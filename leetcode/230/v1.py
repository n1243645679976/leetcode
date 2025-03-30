# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.count = 0
        self.ans = 0
        self.flag = False
        def dfs(node):
            if self.flag:
                return
            if node.left:
                dfs(node.left)
                
            if self.flag:
                return
            self.count += 1
            if self.count == k:
                self.ans = node.val
                self.flag = True
                
            if self.flag:
                return 
            if node.right:
                dfs(node.right)
        dfs(root)
        return self.ans