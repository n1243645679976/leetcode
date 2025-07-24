class Solution:
    def findLucky(self, arr: List[int]) -> int:
        q = Counter(arr)
        ans = max([key if key == q[key] else 0 for key in q.keys()])
        return ans if ans != 0 else -1