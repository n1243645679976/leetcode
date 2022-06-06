class segtree():
    def __init__(self):
        self.lazy = defaultdict(int)
        self.tree = defaultdict(int)
    def update(self, ind, update_l, update_r, recur_l, recur_r, num):
        if recur_l > update_r or recur_r < update_l:
            return
        elif update_l <= recur_l and recur_r <= update_r:
            self.lazy[ind] += num
            self.tree[ind] += num
        else:
            recur_mid = (recur_l + recur_r) // 2
            self.update(ind*2, update_l, update_r, recur_l, recur_mid, num)
            self.update(ind*2+1, update_l, update_r, recur_mid+1, recur_r, num)
            self.tree[ind] = self.lazy[ind] + max(self.tree[ind*2], self.tree[ind*2+1])
