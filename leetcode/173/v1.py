# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.now = root
        self.stack = []
        self.q = None
        self.next()
    def next(self):
        """
        :rtype: int
        """
        while self.now != None:
            self.stack.append(self.now)
            self.now = self.now.left
        if self.stack:
            q = self.stack.pop()
            self.now = q.right
        else:
            q = None
        temp = self.q
        self.q = q
        if temp:
            return temp.val
        else:
            return -1
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.q != None
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()