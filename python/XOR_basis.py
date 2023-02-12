class XOR_basis():
    def __init__(self):
        self.basis = [0] * 32
        self.sz = 0
    def insertVector(self, c):
        if c == 0:
            return
        for i in range(31, -1, -1):
            if ((1<<i) & c) == 0:
                continue
            if self.basis[i] == 0:
                self.basis[i] = c
                self.sz += 1
                return
            c ^= self.basis[i]
    def findMax(self):
        ret = 0
        for i in range(31, -1, -1):
            if self.basis[i] and (ret & (1 << i)) == 0:
                ret ^= self.basis[i]
        return ret
    def mergeBasis(self, xor_basis):
        for b in xor_basis.basis:
            self.insertVector(b)
        
