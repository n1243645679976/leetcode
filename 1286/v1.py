class CombinationIterator(object):

    def __init__(self, characters, combinationLength):
        """
        :type characters: str
        :type combinationLength: int
        """
        self.comb = characters
        self.cl = combinationLength
        self.count = 0
        self.all = ncr(len(characters), self.cl)
        
        def r():
            for i in combinations(self.comb, self.cl):
                self.count += 1
                yield ''.join(i)
        self.r = r()
    def next(self):
        """
        :rtype: str
        """
        return self.r.next()

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.count == self.all:
            return False
        return True
import operator as op
def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom  # or / in Python 2


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()