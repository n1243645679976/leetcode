class Solution(object):
    def threeSumMulti(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        c = Counter(arr)
        q = defaultdict(set)
        keys = c.keys()
        keys.sort()
        ans = 0
        for k in range(len(keys)):
            for j in range(k, len(keys)):
                kk = keys[k]
                kj = keys[j]
                if target - kk - kj < kj:
                    break
                r = Counter([kk, kj, target - kk - kj])
                prod = 1
                for i in r:
                    if r[i] == 3:
                        prod *= c[i] * (c[i] - 1) * (c[i] - 2) / 6
                    elif r[i] == 2:
                        prod *= c[i] * (c[i] - 1) / 2
                    else:
                        prod *= c[i]
                    #print(i, prod)
                ans += prod
        ans %= 1e9 + 7
        ans = int(ans)
        return ans