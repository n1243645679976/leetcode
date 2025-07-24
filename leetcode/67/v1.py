class Solution:
    def addBinary(self, a: str, b: str) -> str:
        c = 0
        ans = []
        for d, e in zip_longest(reversed(a), reversed(b), fillvalue='0'):
            r = int(d)
            e = int(e)
            ans.append(str((r+e+c)&1))
            c = ((r+e+c) & 2)>>1
        if c:
            ans.append('1')
        return ''.join(reversed(ans))
            