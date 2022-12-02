a = 1031237
w = 20
m = 15
def getHash(key):
    return ((key*a) & (1<<w) - 1)>>(w-m)
    
def getInitArray():
    return [[] for _ in range(1<<m)]
    
def getInitBool():
    return [False for _ in range(1<<m)]

def getInitInt():
    return [0 for _ in range(1<<m)]