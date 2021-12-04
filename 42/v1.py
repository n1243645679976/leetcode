class Solution:
    def trap(self, height: List[int]) -> int:
        ma_ind = -1
        ma = -1
        lh = len(height)
        for i in range(lh):
            if height[i] > ma:
                ma = height[i]
                ma_ind = i
        h = [(height[ma_ind], ma_ind)]
        ans = 0
        for i in range(ma_ind-1, -1, -1):
            q = height[i+1]
            while height[i] > h[-1][0]:
                ans += (h[-1][0] - q) * (h[-1][1] - i - 1)
                q, _ind = h.pop()
                #print('!', h, height[i], i, ans)
            if height[i] >= q:
                ans += (height[i] - q) * (h[-1][1] - i - 1)
            h.append((height[i], i))
            #print('@', h, height[i], i, ans)
        
        h = [(height[ma_ind], ma_ind)]
        for i in range(ma_ind+1, lh):
            q = height[i-1]
            while height[i] > h[-1][0]:
                ans += (h[-1][0] - q) * (i - 1 - h[-1][1])
                q, _ind = h.pop()
                #print('!', h, height[i], i, ans)
            if height[i] >= q:
                ans += (height[i] - q) * (i - 1 - h[-1][1])
            h.append((height[i], i))
            #print('@', h, height[i], i, ans)
        return ans
            