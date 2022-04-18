# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def trimBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: TreeNode
        """
        def trim(node):
            if node == None:
                return None
            if node.val > high:
                return trim(node.left)
            if node.val < low:
                return trim(node.right)
            node.left = trim(node.left)
            node.right = trim(node.right)
            return node
        return trim(root)