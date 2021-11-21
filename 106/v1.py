# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder) == 0:
            return None
        n = TreeNode(postorder[-1])
        ind = inorder.index(postorder[-1])
        n.left = self.buildTree(inorder[:ind], postorder[:ind])
        n.right = self.buildTree(inorder[ind+1:], postorder[ind:-1])
        return n