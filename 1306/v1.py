class Solution(object):
    def canReach(self, arr, start):
        """
        :type arr: List[int]
        :type start: int
        :rtype: bool
        """
        visited = set()
        def dfs(ind):
            if ind in visited:
                return False
            if arr[ind] == 0:
                return True
            visited.add(ind)
            addFlag, minusFlag = False, False
            if ind + arr[ind] < len(arr):
                addFlag = dfs(ind+arr[ind])
            if ind - arr[ind] >= 0:
                minusFlag = dfs(ind-arr[ind])
            return addFlag or minusFlag
        return dfs(start)
            