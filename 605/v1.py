class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        c = 0
        for i in range(len(flowerbed)):
            s = i - 1 if i > 0 else 0
            e = i + 2 if i < len(flowerbed) else i + 1
            if sum(flowerbed[s:e]) == 0:
                flowerbed[i] = 1
                c += 1
                if c == n:
                    return True
        if c < n:
            return False
        else:
            return True