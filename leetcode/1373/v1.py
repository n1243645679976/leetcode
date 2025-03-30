# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        def dfs(node):
            lerror, rerror = False, False
            min_list = [node.val]
            max_list = [node.val]
            sum_list = []
            rmi, lma = None, None
            if node.left:
                lerror, lmi, lma, su = dfs(node.left)
                min_list.append(lmi)
                max_list.append(lma)
                sum_list.append(su)
            if node.right:
                rerror, rmi, rma, su = dfs(node.right)
                min_list.append(rmi)
                max_list.append(rma)
                sum_list.append(su)
            # check if node is leaf
            if len(min_list) == 0:
                self.ans = max(self.ans, node.val)
                return False, node.val, node.val, node.val
            
            # check not BST
            if lerror or rerror:
                return True, 0, 0, max(sum_list)
            
            # check left and right
            if rmi != None and rmi <= node.val:
                return True, 0, 0, max(sum_list)
            if lma != None and lma >= node.val:
                return True, 0, 0, max(sum_list)
            
            self.ans = max(self.ans, sum(sum_list) + node.val)
            return False, min(min_list), max(max_list), sum(sum_list) + node.val
        dfs(root)
        return self.ans
            
            