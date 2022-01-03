class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def getKey(x):
            q = 0
            _x = x
            while _x:
                q += (_x&1)
                _x >>= 1
            return (q, x)
        return sorted(arr, key=getKey)
                