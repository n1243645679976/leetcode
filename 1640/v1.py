import itertools
class Solution(object):
    def canFormArray(self, arr, pieces):
        """
        :type arr: List[int]
        :type pieces: List[List[int]]
        :rtype: bool
        """
        if len(set(list(itertools.chain.from_iterable(pieces))).intersection(set(arr))) == len(arr):
            return True
        return False