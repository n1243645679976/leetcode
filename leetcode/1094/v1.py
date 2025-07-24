class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        d = []
        for t in trips:
            d.append((t[1], t[0]))
            d.append((t[2], -t[0]))
        d = sorted(d)
        for p, _n in d:
            capacity -= _n
            if capacity < 0:
                return False
        return True
            