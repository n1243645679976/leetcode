class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def check(self, mid, nums, m):
            c = 0
            for num in nums:
                if c + num <= mid:
                    c += num
                else:
                    c = num
                    m -= 1
                    if m < 0:
                        return False
            return True
        l = max(nums)
        r = sum(nums)
        while l < r:
            mid = (l+r) // 2
            if check(mid, nums, m-1):
                r = mid
            else:
                l = mid + 1
        return l
        