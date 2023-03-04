class segtree():
    def __init__(self, type):
        self.lazy = defaultdict(int)
        self.tree = defaultdict(int)
        if type == 'plus_max':
            self.proplazy = _plus_max_proplazy
            self.update = _plus_max_update
            self.query = _plus_max_query
        elif type == 'set_max':
            self.proplazy = _set_max_proplazy
            self.update = _set_max_update
            self.query = _set_max_query
        else:
            raise NotImplementedError(f'not implemented segtree {type=}')
            
    def _plus_max_proplazy(self, ind):
    # plus
        self.lazy[ind*2] += self.lazy[ind]
        self.tree[ind*2] += self.lazy[ind]
        self.lazy[ind*2 + 1] += self.lazy[ind]
        self.tree[ind*2 + 1] += self.lazy[ind]
        self.tree[ind] = max(self.tree[ind*2], self.tree[ind*2+1])
        self.lazy[ind] = 0
        
    def _plus_max_update(self, ind, ul, ur, cl, cr, val):
    # plus
        if cl > ur or cr < ul:
            return 
        if ul <= cl and cr <= ur:
            self.lazy[ind] += val
            self.tree[ind] += val
        else:
            mid = (cl + cr) // 2
            self._plus_max_proplazy(ind)
            self._plus_max_update(ind*2, ul, ur, cl, mid, val)
            self._plus_max_update(ind*2+1, ul, ur, mid+1, cr, val)
            self.tree[ind] = max(self.tree[ind*2], self.tree[ind*2+1])
           
    def _plus_max_query(self, ind, ul, ur, cl, cr):
    # plus
        if cl > ur or cr < ul:
            return 0
        if ul <= cl and cr <= ur:
            return self.tree[ind]
        else:
            mid = (cl + cr) // 2
            self._plus_max_proplazy(ind)
            # 不要複寫self.tree[ind], 因為(cl, cr)不一定是ind的所有範圍
            return max(self._plus_max_query(ind*2, ul, ur, cl, mid), self._plus_max_query(ind*2+1, ul, ur, mid+1, cr))
         
    def _set_max_proplazy(self, ind):
        self.lazy[ind*2] = max(self.lazy[ind*2], self.lazy[ind])
        self.tree[ind*2] = max(self.tree[ind*2], self.lazy[ind*2])
        self.lazy[ind*2 + 1] = max(self.lazy[ind*2+1], self.lazy[ind])
        self.tree[ind*2 + 1] = max(self.tree[ind*2+1], self.lazy[ind*2+1])
        self.tree[ind] = max(self.tree[ind*2], self.tree[ind*2+1])
        self.lazy[ind] = 0
        
    def _set_max_update(self, ind, ul, ur, cl, cr, val):
        if cl > ur or cr < ul:
            return 
        if ul <= cl and cr <= ur:
            self.lazy[ind] = max(val, self.lazy[ind])
            self.tree[ind] = max(val, self.tree[ind])
        else:
            mid = (cl + cr) // 2
            self._set_max_proplazy(ind)
            self._set_max_update(ind*2, ul, ur, cl, mid, val)
            self._set_max_update(ind*2+1, ul, ur, mid+1, cr, val)
            self.tree[ind] = max(self.tree[ind*2], self.tree[ind*2+1])
            
    def _set_max_query(self, ind, ul, ur, cl, cr):
        if cl > ur or cr < ul:
            return 0
        if ul <= cl and cr <= ur:
            return self.tree[ind]
        else:
            mid = (cl + cr) // 2
            self._set_max_proplazy(ind)
            # 不要複寫self.tree[ind], 因為(cl, cr)不一定是ind的所有範圍
            return max(self._set_max_query(ind*2, ul, ur, cl, mid), self._set_max_query(ind*2+1, ul, ur, mid+1, cr))
        
# update one point, query an interval
class SEG:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * 2 * self.n
       
    def query(self, l, r):
        l += self.n
        r += self.n
        ans = 0
        while l < r:
            if l & 1:
                ans = max(ans, self.tree[l])
                l += 1
            if r & 1:
                r -= 1
                ans = max(ans, self.tree[r])
            l >>= 1
            r >>= 1
        return ans
    
    def update(self, i, val):
        i += self.n
        self.tree[i] = val
        while i > 1:
            i >>= 1
            self.tree[i] = max(self.tree[i * 2], self.tree[i * 2 + 1])
class SEG:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * 2 * self.n
       
    def query(self, l, r):
        l += self.n
        r += self.n
        ans = 0
        while l < r:
            if l & 1:
                ans += self.tree[l]
                l += 1
            if r & 1:
                r -= 1
                ans += self.tree[r]
            l >>= 1
            r >>= 1
        return ans
    
    def update(self, i, val):
        i += self.n
        self.tree[i] += val
        while i > 1:
            i >>= 1
            self.tree[i] = self.tree[i * 2] + self.tree[i * 2 + 1]