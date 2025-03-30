def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        g = gcd(len(nums), k)
        for i in range(g):
            temp = nums[i+k]
            nums[i+k] = nums[i]
            r = i + k
            while r != i:
                tar = r + k
                if tar >= len(nums):
                    tar -= len(nums)
                temp1 = nums[tar]
                nums[tar] = temp
                temp = temp1
                r = tar
                