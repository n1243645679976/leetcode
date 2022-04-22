a = 1031237
w = 25
m = 20
def getHash(key):
    return ((key*a) & (1<<w) - 1)>>(w-m)
    
def getInitArray():
    return [[] for _ in range(1<<m)]
    
def getInitBool():
    return [False for _ in range(1<<m)]

def getInitInt():
    return [-1 for _ in range(1<<m)]

class MyHashMap(object):

    def __init__(self):
        self.bucket = getInitInt()

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        self.bucket[getHash(key)] = value

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        return self.bucket[getHash(key)]

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        self.bucket[getHash(key)] = -1
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)