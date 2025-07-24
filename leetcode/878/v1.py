def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)
class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        gcdab = gcd(a,b)
        lcm = a*b//gcdab
        def checkMagic(mid):
            now = mid // a + mid // b - mid // lcm
            if now % a != 0 and now % b != 0:
                return now
            else:
                return now
        l = 0
        r = n * min(a, b)
        while l < r:
            mid = (l+r)//2
            if checkMagic(mid) < n:
                l = mid + 1
            else:
                r = mid
        return int(l % (1e9+7))
        