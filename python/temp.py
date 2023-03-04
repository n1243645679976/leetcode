new_input = True
if new_input:
    import io,os
    def ginput():
        for line in io.BytesIO(os.read(0,os.fstat(0).st_size)).read().decode().splitlines():
            yield line
    input = ginput()
 #   import sys
 #   print = lambda n: sys.stdout.write(str(n))
    def getint():
        return int(next(input))
    def getfloat():
        return float(next(input))
    def getints():
        return list(map(int, next(input).split()))
    def getfloats():
        return list(map(float, next(input).split()))
    def getstr():
        return next(input)
else:
    from collections import deque
    def getint():
        return int(input())
    def getfloat():
        return float(input())
    def getints():
        return list(map(int, input().split()))
    def getfloats():
        return list(map(float, input().split()))
    def getstr():
        return input()
class UnionFind():
    def __init__(self, n):
        self.parent = [i for i in range(n)]
    def union(self, a, b):
        if self.find(a) != self.find(b):
            self.parent[self.parent[b]] = self.parent[a]
            self.find(b)
            self.find(a)
    def find(self, a):
        if self.parent[a] == a:
            return a
        else:
            self.parent[a] = self.find(self.parent[a])
            return self.parent[a]
    def maxunion(self):
        mac = 0
        count = Counter()
        for i in self.parent:
            self.find(i)
            count[self.parent[i]] += 1
            mac = max(mac, count[self.parent[i]])
        return mac

# class groupby:
#     # [k for k, g in groupby('AAAABBBCCDAABBB')] --> A B C D A B
#     # [list(g) for k, g in groupby('AAAABBBCCD')] --> AAAA BBB CC D

#     def __init__(self, iterable, key=None):
#         if key is None:
#             key = lambda x: x
#         self.keyfunc = key
#         self.it = iter(iterable)
#         self.tgtkey = self.currkey = self.currvalue = object()

#     def __iter__(self):
#         return self

#     def __next__(self):
#         self.id = object()
#         while self.currkey == self.tgtkey:
#             self.currvalue = next(self.it)    # Exit on StopIteration
#             self.currkey = self.keyfunc(self.currvalue)
#         self.tgtkey = self.currkey
#         return (self.currkey, self._grouper(self.tgtkey, self.id))

#     def _grouper(self, tgtkey, id):
#         while self.id is id and self.currkey == tgtkey:
#             yield self.currvalue
#             try:
#                 self.currvalue = next(self.it)
#             except StopIteration:
#                 return
#             self.currkey = self.keyfunc(self.currvalue)
# from itertools import tee
# def pairwise(iterable):
#     # pairwise('ABCDEFG') --> AB BC CD DE EF FG
#     a, b = tee(iterable)
#     next(b, None)
#     return zip(a, b)
import heapq
from collections import defaultdict, Counter
import sys

def answer():
    n, k = getints()
    s = getstr()
    t = getstr()
    uf = UnionFind(n+100)
    for i in range(len(s)):
        if i + k <n:
            uf.union(i, i+k)
        if i + k + 1 < n:
            uf.union(i, i+k+1)
    c = defaultdict(Counter)
    d = defaultdict(Counter)
    for i in range(len(s)):
        c[uf.find(i)][s[i]] += 1
        d[uf.find(i)][t[i]] += 1
    ans = True
    for v1, v2 in zip(c.values(), d.values()):
        if v1 != v2:
            print('NO')
            return
    print('YES')
    
        



T = getint()
for i in range(T):
    answer()