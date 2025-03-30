class Solution:

    def __init__(self, rects: List[List[int]]):
        
        self.choice = list(range(len(rects)))
        self.cum_weight = []
        _sum = 0
        self.width = []
        for x1, y1, x2, y2 in rects:
            _sum += (x2-x1+1) * (y2-y1+1)
            self.cum_weight.append(_sum)
            self.width.append(x2-x1+1)
        self.rects = rects

    def pick(self) -> List[int]:
        
        ind = random.choices(self.choice, cum_weights=self.cum_weight)
        ind = ind[0]
        if ind != 0:
            point_ind = random.uniform(0, self.cum_weight[ind] - self.cum_weight[ind-1])
        else:
            point_ind = random.uniform(0, self.cum_weight[0])
        point_ind = floor(point_ind)
        #print(point_ind)
        
        new_x1 = self.rects[ind][0] + floor(point_ind) % self.width[ind]
        new_y1 = self.rects[ind][1] + point_ind // self.width[ind]
        return [new_x1, new_y1]
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()