class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        return all(b >= a for a, b in pairwise(nums)) or all(a >= b for a, b in pairwise(nums))