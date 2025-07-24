class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        def dfs(node):
            leftSum, leftTilt = dfs(node.left) if node.left else (0, 0)
            rightSum, rightTilt = dfs(node.right) if node.right else (0, 0)
            
            return leftSum + rightSum + node.val, leftTilt + rightTilt + abs(leftSum - rightSum)
        return dfs(root)[1]