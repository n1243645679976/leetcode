def getint():
    return int(input())
def getfloat():
    return float(input())
def getints():
    return list(map(int, input().split()))
def getfloats():
    return list(map(float, input().split()))

from XOR_basis import XOR_basis
T = getint()
for i in range(T):
    n = getint()
    xor = XOR_basis()
    g = getints()
    for i in g:
        xor.insertVector(i)
    print(xor.findMax())