class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        d = {q: 0 for q in random.choices(arr, k=20)}
        tarnum = (len(arr)+4)//4
        for a in arr:
            if a in d:
                d[a] += 1
                if d[a] == tarnum:
                    return a
        