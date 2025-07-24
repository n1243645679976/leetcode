class Solution:
    def addDigits(self, num: int) -> int:
        while num // 10 != 0:
            q = 0
            while num:
                q += num % 10
                num //= 10
            num = q
        return num