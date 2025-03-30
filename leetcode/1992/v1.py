class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        lx = len(land)
        ly = len(land[0])
        ans = []
        for i in range(lx):
            for j in range(ly):
                if land[i][j] == 2:
                    continue
                if land[i][j] == 1:
                    k = i
                    while k < lx:
                        if land[k][j] == 0:
                            break
                        k += 1
                    l = j
                    while l < ly:
                        if land[i][l] == 0:
                            break
                        l += 1
                    ans.append([i, j, k-1, l-1])
                    for kk in range(i, k):
                        for ll in range(j, l):
                            land[kk][ll] = 2
        return ans