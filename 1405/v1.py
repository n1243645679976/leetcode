class Solution(object):
    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """
        symbols = [(a, 'a'), (b, 'b'), (c, 'c')]
        symbols.sort(reverse=True)
        
        chunk_size = 2
        def get_chunked(symbol, q=2):
            if symbol[0] == 0:
                return []
            chunked = [symbol[1]*q for i in range(0, symbol[0]-1, q)]
            if symbol[0] & 1 and q == 2:
                chunked.append(symbol[1])
            if q == 1:
                chunked.append(symbol[1])
            return chunked
        ans = get_chunked(symbols[0])
        ans1 = get_chunked(symbols[1],1) + get_chunked(symbols[2],1)
        diff = 1
        i = 0
        maxi = (symbols[0][0] + 1) // 2
        for a in ans1:
            ans.insert((diff+1)*i + diff, a)
            i += 1
            if i == maxi:
                i = 0
                diff += 1
            #print(ans)
        while len(ans) > 1 and ans[-1][0] == ans[-2][0] and ans[-1][0] == symbols[0][1]:
            ans.pop()
        return ''.join(ans)