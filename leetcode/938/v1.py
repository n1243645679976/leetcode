class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        def dfs(node):
            ans = node.val if node.val >= low and node.val <= high else 0
            if node.val >= low:
                ans += dfs(node.left) if node.left else 0
            if node.val <= high:
                ans += dfs(node.right) if node.right else 0
            return ans
        return dfs(root)
            