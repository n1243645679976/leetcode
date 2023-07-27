new_input = False
if new_input:
    import io,os
    def ginput():
        for line in io.BytesIO(os.read(0,os.fstat(0).st_size)).read().decode().splitlines():
            yield line
    input = ginput()
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
    def getstrs():
        return next(input).split()
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

from sys import stdout
def printf(*args):
    print(*args)
    stdout.flush()
    
class groupby:
    # [k for k, g in groupby('AAAABBBCCDAABBB')] --> A B C D A B
    # [list(g) for k, g in groupby('AAAABBBCCD')] --> AAAA BBB CC D

    def __init__(self, iterable, key=None):
        if key is None:
            key = lambda x: x
        self.keyfunc = key
        self.it = iter(iterable)
        self.tgtkey = self.currkey = self.currvalue = object()

    def __iter__(self):
        return self

    def __next__(self):
        self.id = object()
        while self.currkey == self.tgtkey:
            self.currvalue = next(self.it)    # Exit on StopIteration
            self.currkey = self.keyfunc(self.currvalue)
        self.tgtkey = self.currkey
        return (self.currkey, self._grouper(self.tgtkey, self.id))

    def _grouper(self, tgtkey, id):
        while self.id is id and self.currkey == tgtkey:
            yield self.currvalue
            try:
                self.currvalue = next(self.it)
            except StopIteration:
                return
            self.currkey = self.keyfunc(self.currvalue)
from itertools import tee
from heapq import heappush, heappop
from collections import defaultdict, Counter, deque
import math
import sys
    
sys.setrecursionlimit(100000)

def pairwise(iterable):
    # pairwise('ABCDEFG') --> AB BC CD DE EF FG
    a, b = tee(iterable)
    next(b, None)
    return zip(a, b)

from itertools import combinations
class UnionFind():
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.pdis = [0 for i in range(n)]
    def unite(self, a, b, c):
        # a - b = c
        if self.find(a) != self.find(b):
            self.pdis[self.parent[b]] = self.pdis[a] + c - self.pdis[b]
            self.parent[self.parent[b]] = self.parent[a]
    def find(self, a):
        if self.parent[a] == a:
            return (0, a)
        else:
            dis, self.parent[a] = self.find(self.parent[a])
            self.pdis[a] += dis
            return (dis + self.pdis[a], self.parent[a])
    def maxunion(self):
        mac = 0
        count = Counter()
        for i in self.parent:
            self.find(i)
            count[self.parent[i]] += 1
            mac = max(mac, count[self.parent[i]])
        return mac
def bisect_left(a, x, lo=0, hi=None, *, key=None):
    """Return the index where to insert item x in list a, assuming a is sorted.

    The return value i is such that all e in a[:i] have e < x, and all e in
    a[i:] have e >= x.  So if x already appears in the list, a.insert(i, x) will
    insert just before the leftmost x already there.

    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched.
    """

    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    # Note, the comparison uses "<" to match the
    # __lt__() logic in list.sort() and in heapq.
    if key is None:
        while lo < hi:
            mid = (lo + hi) // 2
            if a[mid] < x:
                lo = mid + 1
            else:
                hi = mid
    else:
        while lo < hi:
            mid = (lo + hi) // 2
            if key(a[mid]) < x:
                lo = mid + 1
            else:
                hi = mid
    return lo
inf = float('inf')
def answer():
    n, m = getints()
    uf = UnionFind(n+1)
    f = [getints() for i in range(m)]
    for i in range(m):
        a, b, d = f[i]
        uf.unite(a, b, d)
    for i in range(n):
        uf.find(i)
    for i in range(m):
        a, b, d = f[i]
        if uf.pdis[b] - uf.pdis[a] != d:
            return False
    return True
    if not flag:
        return False
    return True
        
        
        
            
    
T = 1
T = getint()
for i in range(T):
    q = answer()
    if q != None:
        if q:
            print('Yes')
        else:
            print('No')
            