class Solution(object):
    def findNumOfValidWords(self, words, puzzles):
        """
        :type words: List[str]
        :type puzzles: List[str]
        :rtype: List[int]
        """
        wf = defaultdict(int)
        for w in words:
            a = 0
            for c in w:
                a |= 1 << (ord(c) - 97)
            wf[a] += 1

        puzzle_hash = []
        puzzle_first = []  
        for p in puzzles:
            puzzle_hash.append(a)
            puzzle_first.append(1<<(ord(p[0])-97))
        
        ans = []
        for p in puzzles:
            mask = 0
            _sum = 0
            first = 1<<(ord(p[0])-97)
            for c in p:
                mask |= 1 << (ord(c) - 97)
            submask = mask
            while submask:
                if submask & first:
                    _sum += wf[submask]
                submask = (submask-1) & mask
            
            ans.append(_sum)
        return ans