# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        r = []
        def dfs(node):
            if node.left:
                dfs(node.left)
            r.append(node.val)
            if node.right:
                dfs(node.right)
        if root:
            dfs(root)
        rr = TreeNode()
        n = rr
        for _r in r:
            n.right = TreeNode(_r)
            n = n.right
        return rr.right