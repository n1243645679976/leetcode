class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        n = Counter(nums)
        q = list(sorted(n.keys()))
        ans = 0
        for r in range(len(q)-1, 0, -1):
            ans += n[q[r]]
            n[q[r-1]] += n[q[r]]
        return ans
            