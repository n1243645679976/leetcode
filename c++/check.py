
from itertools import tee, combinations
from heapq import heappush, heappop
from collections import defaultdict, Counter, deque
from sys import stdout
import math
import sys
sys.setrecursionlimit(100000) # 100000 -> 130MB and 300000 -> exceed 256MB
def printf(*args):
    print(*args)
    stdout.flush()
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
    def getstrs():
        return input().split()

inf = float('inf')
    
class groupby:
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

def pairwise(iterable): a, b = tee(iterable); next(b, None); return zip(a, b)
import itertools
def bisect_left(a, x, lo=0, hi=None, *, key=None):
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
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
def gcd(a, b): return gcd(b%a, a) if a != 0 else b
def sgn(x): return (x>0) - (x<0)
from functools import lru_cache
from itertools import product, permutations
DOT = 1

def popcount(a):
    return bin(a).count('1')
def listn(n):
    return [-1] * n

def answer():
    n, k = getints()
    a = getints()
    b = getints()
    ans = 0
    ansaa = []
    ansbb = []
    for i in range(1<<n):
        su = 0
        aa = []
        bb = []
        for j in range(n):
            if (1<<j) & i:
                su += a[j]
                aa.append(a[j])
                bb.append(b[j])
        bb.sort(reverse=True)
        su = sum(bb[k:]) - su
        if su > ans:
            ans = max(ans, su)
            ansaa = aa
            ansbb = bb
    print(ans, ansaa, ansbb)




T = 1
if DOT:
    T = getint()
for i in range(T):
    q = answer()
    if q != None:
        if q:
            print('Yes')
        else:
            print('No')
            