
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = list(map(int, version1.split('.')))
        v2 = list(map(int, version2.split('.')))
        for _v1, _v2 in zip_longest(v1, v2, fillvalue=0):
            if _v1 > _v2:
                return 1
            if _v2 > _v1:
                return -1
        return 0
        