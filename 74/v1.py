class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for v in zip(*matrix):
            rind = bisect.bisect(v, target)
            break
        if rind == 0:
            return False
        cind = bisect.bisect(matrix[rind-1], target)
        return (cind != 0) and (matrix[rind-1][cind-1] == target)