
from itertools import tee, combinations
from heapq import heappush, heappop
from collections import defaultdict, Counter, deque
from sys import stdout
import math
import sys
sys.setrecursionlimit(100000)
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
def inv(a):
    cnt = 0
    for i in range(len(a)):
        for j in range(i):
            if a[j] > a[i]:
                cnt+=1
    return cnt
def test():
    import random
    for i in range(10000):
        a, b, r = random.randint(1, 15), random.randint(1, 15), random.randint(1, 15)
        answer(1,2,3)
        break
        #if answer(a, b, r)[0] != answer1(a, b, r)[0]:
        #    print('a', answer(a, b, r), answer1(a, b, r))
        #    print(a, b, r)
        #    break
def answer1(a, b, r):
    ans = inf
    ansi = inf
    for i in range(r+1):
        if abs((a^i) - (b^i)) < ans:
            ans = abs((a^i) - (b^i))
            ansi = i
    return ans, ansi
def answer(a, b, r):
    a, b, r = [12,2,9]
    k = 1
    while (k << 1) < r:
        k <<= 1
    ans = 0
    while k:
        if (a & k == k) and (b & k == k):
            k >>= 1
            continue
        elif (a & k == 0) and (b & k == 0):
            k >>= 1
            continue
        elif ans + k <= r:
            print('pre', abs((a ^ (ans + k)) - (b ^ (ans + k))))
            print(abs((a ^ (ans)) - (b ^ ans)))
            print(ans, k)
            if abs((a ^ (ans + k)) - (b ^ (ans + k))) < abs((a ^ (ans)) - (b ^ ans)):
                ans += k
        k >>= 1
    gr = answer1(a, b, r)[1]
    print(answer1(a, b, r))
    print('gr', gr)
    print(abs((a^gr) - (b^gr)))
    print(abs((a^r) - (b^r)))
    return abs((a ^ (ans)) - (b ^ ans)), ans
        
        
    
T = 1
#T = getint()
for i in range(T):
    test()
    q = None
    #q = answer()
    if q != None:
        if q:
            print('Yes')
        else:
            print('No')
            