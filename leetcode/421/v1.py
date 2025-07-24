class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        answer = 0
        for i in range(32)[::-1]:
            answer <<= 1
            prefix = {n >> i for n in nums}
            answer += any(answer^1 ^ p in prefix for p in prefix)
        return answer