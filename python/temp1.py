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

class BIT:
    def __init__(self, n):
        # valid input: [0, n]
        self.sums = [0] * (n+3)
    
    def update(self, i, delta):
        # update >=i with delta
        i += 2
        while i < len(self.sums):
            self.sums[i] += delta
            i += i & (-i)
    def _query(self, i):
        # get (0, i]
        i += 2
        res = 0
        while i > 0:
            res += self.sums[i]
            i -= i & (-i)
        return res
    
    def query(self, i, j =None):
        # [0, i] or [i, j]
        if j == None:
            return self._query(i)
        else:
            assert j >= i
            return self._query(j) - self._query(i-1)
        
    def update_interval(self, a, b, delta):
        # update [b, a]
        self.update(a+1, -delta)
        self.update(b, delta)
    
def popcount(a):
    return bin(a).count('1')
def ctz(a):
    return len(bin(a).split('1')[-1])
def __lg(a):
    return len(bin(a).split('1', 1)[1])
def listn(n):
    return [-1] * n
def answer():
    

DOT = 0
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
            