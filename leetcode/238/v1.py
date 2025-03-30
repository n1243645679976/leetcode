class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        lr = []
        rl = deque()
        prod = 1
        for num in nums:
            lr.append(prod)
            prod *= num
        prod = 1
        for num in nums[::-1]:
            rl.appendleft(prod)
            prod *= num
        return [a*b for a, b in zip(lr, rl)]
            