   
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        tar = sum(nums)
        if tar & 1 == 1:
            return False
        tar = tar // 2
        a = [0] * (tar+1)
        ma = 0
        a[0] = 1
        for num in nums:
            for i in range(ma, -1, -1):
                if a[i] and num+i <= tar:
                    a[num+i] = 1
                    ma = max(num+i, ma)
                    if num + i == tar:
                        #print(a)
                        return True
        #print(a)
        return False