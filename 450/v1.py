# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
        
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        
        if root == None:
            return root
        dummy = TreeNode(-1000000)
        dummy.right = root
        
        node = dummy
        prenode = dummy
        while node:
            print(prenode.val, node.val)
            if node.val > key:
                prenode = node
                node = node.left
                l = 1
            elif node.val < key:
                prenode = node
                node = node.right
                l = 0
            else:
                break
        if node == None:
            return dummy.right
        
        if node.left and node.right:
            maxnode = node.left
            if l:
                prenode.left = node.left
            else:
                prenode.right = node.left
            while maxnode.right:
                maxnode = maxnode.right
            maxnode.right = node.right
        else:
            if node.left:
                if l:
                    prenode.left = node.left
                else:
                    prenode.right = node.left
            elif node.right:
                if l:
                    prenode.left = node.right
                else:
                    prenode.right = node.right
            else:
                if l:
                    prenode.left = None
                else:
                    prenode.right = None
        return dummy.right