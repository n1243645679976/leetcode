# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        
        def sumtree(node):
            s = 0
            if node.left:
                s += sumtree(node.left)
            if node.right:
                s += sumtree(node.right)
            return s + node.val
        s = sumtree(root)
        
        ans = 0
        def dfs(node):
            nonlocal ans
            l, r = 0, 0
            if node.left:
                l = dfs(node.left)
                ans = max(ans, l * (s - l))
            if node.right:
                r = dfs(node.right)
                ans = max(ans, r * (s - r))
            return l + r + node.val
        dfs(root)
        
        return int(ans % (1e9+7))