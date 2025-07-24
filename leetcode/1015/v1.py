class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k & 1 == 0:
            return -1
        if k % 5 == 0:
            return -1
        q = 1
        ans = 1
        while q:
            if q >= k:
                q %= k
                if q == 0:
                    return ans
            q *= 10
            q += 1
            ans += 1
            