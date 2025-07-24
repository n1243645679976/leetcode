# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        dummy = TreeNode(-1e9)
        dummy.right = root
        node = dummy
        newnode = TreeNode(val)
        while node:
            if val > node.val:
                if node.right:
                    node = node.right
                else:
                    node.right = newnode
                    break
            if val < node.val:
                if node.left:
                    node = node.left
                else:
                    node.left = newnode
                    break
        return dummy.right